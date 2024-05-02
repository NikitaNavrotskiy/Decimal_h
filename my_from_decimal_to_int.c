#include "my_decimal.h"

int big_from_decimal_to_int(big_decimal src, int *dst) {
  int err = OK;
  int res = 0;
  int scale = get_scale(src);

  for (int i = scale + 32; i <= 223; i++) {
    if (get_bit(src, i)) err = CONVERT_ERROR;
  }

  if (!err) {
    for (int i = scale + 30; i >= scale; --i) {
      res <<= 1;
      res |= get_bit(src, i);
    }
    if (get_bit(src, BIG_SIGN_BIT) == MINUS) res = -res;
    *dst = res;
  }

  return err;
}

int my_from_decimal_to_int(my_decimal src, int *dst) {
  big_decimal tmp;

  from_dec_to_bigdec(src, &tmp);
  big_from_decimal_to_int(tmp, dst);

  return OK;
}