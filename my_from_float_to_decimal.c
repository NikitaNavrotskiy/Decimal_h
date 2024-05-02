#include "my_decimal.h"

int big_from_float_to_decimal(float src, big_decimal *dst) {
  int res = OK;
  int scale = 0;
  set_all_null(dst);
  if (src) {
    if (src < 0) {
      set_bit(dst, MINUS, BIG_SIGN_BIT);
      src = -src;
    }
    uint32_t bits = *(uint32_t *)(void *)&src;
    int8_t exp = ((bits >> 23) & 0b11111111) - 127;
    if (exp > 95)
      res = 1;
    else {
      normalize_float(&src, &scale);
      bits = *(int *)(void *)&src;
      exp = ((bits >> 23) & 0b11111111) - 127;
      if (exp < -94 || scale > 28) res = 1;
      set_bit(dst, 1, exp);
      for (int i = 22; i >= 0 && exp > 0; i--) {
        exp--;
        if ((bits & 1 << i) >> i) set_bit(dst, 1, exp);
      }
      if (scale)
        dst->bits[7] |= scale << 16;
      else
        res = 1;
    }
  }
  if (res) set_all_null(dst);

  return res;
}

int my_from_float_to_decimal(float src, my_decimal *dst) {
  big_decimal tmp;

  big_from_float_to_decimal(src, &tmp);
  return from_bigdec_to_dec(tmp, dst);
}

/* #include <stdio.h>
int main()
{
  float a = 342.342, res;
  big_decimal a_ = {0};
  big_from_float_to_decimal(a, &a_);
  big_from_decimal_to_float(a_, &res);
  float a = 5631345.0f;
  my_decimal exp = {{5631345, 0, 0, 0}};
  my_decimal res;
  my_from_float_to_decimal(a, &res);
  printf("%f     %f", a, res);
} */