#include "my_decimal.h"

int big_mul(big_decimal value_1, big_decimal value_2, big_decimal *result) {
  int err = OK;
  int sign = PLUS;
  big_decimal tmp = {0};
  set_all_null(result);
  int scale1 = get_scale(value_1);
  int scale2 = get_scale(value_2);
  if (scale1 + scale1 > 28)
    err = TOO_LARGE;
  else {
    if (get_bit(value_1, BIG_SIGN_BIT) != get_bit(value_2, BIG_SIGN_BIT))
      sign = MINUS;
    set_scale(&value_1, 0);
    set_scale(&value_2, 0);
    copy(&tmp, value_1);

    for (int i = 0; i < 224; i++) {
      if (get_bit(value_2, i)) {
        err = big_add(*result, tmp, result);
      }
      left_shift(&tmp);
    }
    set_bit(result, sign, BIG_SIGN_BIT);
    set_scale(result, scale1 + scale2);
  }
  return err;
}

int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int ret = OK;
  big_decimal val1 = {0}, val2 = {0}, res = {0};
  from_dec_to_bigdec(value_1, &val1);
  from_dec_to_bigdec(value_2, &val2);
  ret = big_mul(val1, val2, &res);

  if (res.bits[3] || res.bits[4] || res.bits[5] || res.bits[6])
    ret = TOO_LARGE;
  else
    from_bigdec_to_dec(res, result);

  return ret;
}