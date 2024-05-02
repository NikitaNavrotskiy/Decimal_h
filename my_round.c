#include "my_decimal.h"

int big_round(big_decimal value, big_decimal *result) {
  set_all_null(result);
  int res = OK;
  int sign = get_bit(value, BIG_SIGN_BIT);
  set_bit(&value, PLUS, BIG_SIGN_BIT);
  big_decimal val_without_scale = {{0, 0, 0, 0, 0, 0, 0, 0}};
  big_decimal five = {{5, 0, 0, 0, 0, 0, 0, 0}};
  set_scale(&five, 1);
  big_decimal tmp = {{0, 0, 0, 0, 0, 0, 0, 0}};
  big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  big_truncate(value, &val_without_scale);
  big_sub(value, val_without_scale, &tmp);

  if (big_is_greater_or_equal(tmp, five)) {
    big_add(val_without_scale, one, result);
    set_scale(result, 0);
    set_bit(result, sign, BIG_SIGN_BIT);
  } else {
    *result = val_without_scale;
    set_scale(result, 0);
    set_bit(result, sign, BIG_SIGN_BIT);
  }
  return res;
}

int my_round(my_decimal value, my_decimal *result) {
  int res = 0;
  big_decimal val = {0};
  from_dec_to_bigdec(value, &val);
  res = big_round(val, &val);
  from_bigdec_to_dec(val, result);
  return res;
}