#include "my_decimal.h"

int big_truncate(big_decimal value, big_decimal *result) {
  int err = OK;

  set_all_null(result);

  big_decimal integ = {0};
  copy(&integ, value);
  int scale = get_scale(value);
  for (int i = 0; i < scale; i++) div_by_10(&integ);
  set_scale(&integ, 0);
  copy(result, integ);

  return err;
}

int my_truncate(my_decimal value, my_decimal *result) {
  int res = 0;
  big_decimal val = {0};
  from_dec_to_bigdec(value, &val);
  res = big_truncate(val, &val);
  from_bigdec_to_dec(val, result);

  return res;
}