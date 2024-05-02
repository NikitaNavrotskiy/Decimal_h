#include "my_decimal.h"

int big_floor(big_decimal value, big_decimal *result) {
  int err = OK;
  big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  big_decimal zero = {0};
  set_all_null(result);
  if (get_scale(value) == 0)
    copy(result, value);
  else {
    big_truncate(value, result);
    if (big_is_less(value, zero)) big_sub(*result, one, result);
  }

  return err;
}

int my_floor(my_decimal value, my_decimal *result) {
  int res = 0;
  big_decimal val;
  from_dec_to_bigdec(value, &val);
  res = big_floor(val, &val);
  from_bigdec_to_dec(val, result);

  return res;
}