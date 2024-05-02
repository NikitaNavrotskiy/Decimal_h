#include "my_decimal.h"

int big_from_decimal_to_float(big_decimal src, float *dst) {
  int ret = OK;
  double res = 0.0;
  for (int i = 0; i < 96; i++)
    if (get_bit(src, i) == 1) res += pow(2, i);
  if (get_bit(src, BIG_SIGN_BIT) == MINUS) res = -res;
  *dst = res / pow(10, get_scale(src));

  return ret;
}

int my_from_decimal_to_float(my_decimal src, float *dst) {
  big_decimal tmp;

  from_dec_to_bigdec(src, &tmp);
  big_from_decimal_to_float(tmp, dst);

  return OK;
}