#include "my_decimal.h"

int big_add(big_decimal value_1, big_decimal value_2, big_decimal *result) {
  int res = OK;

  make_scale_equal(&value_1, &value_2);

  res = add_same_scales(value_1, value_2, result);

  return res;
}

int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int ret = OK;
  big_decimal val1 = {0}, val2 = {0}, res = {0};
  from_dec_to_bigdec(value_1, &val1);
  from_dec_to_bigdec(value_2, &val2);
  big_add(val1, val2, &res);

  ret = from_bigdec_to_dec(res, result);

  return ret;
}
