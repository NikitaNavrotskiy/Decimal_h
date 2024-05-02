#include "my_decimal.h"

int big_from_int_to_decimal(int src, big_decimal *dst) {
  int sign = PLUS;

  set_all_null(dst);

  if (src < 0) {
    sign = MINUS;
    src = -src;
  }

  dst->bits[0] = src;
  set_scale(dst, 0);
  set_bit(dst, sign, BIG_SIGN_BIT);

  return OK;
}

int my_from_int_to_decimal(int src, my_decimal *dst) {
  big_decimal tmp;

  big_from_int_to_decimal(src, &tmp);
  from_bigdec_to_dec(tmp, dst);

  return OK;
}