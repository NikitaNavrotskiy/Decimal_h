#include "my_decimal.h"

int big_negate(big_decimal value, big_decimal *result) {
  if (get_bit(value, BIG_SIGN_BIT) == PLUS)
    set_bit(&value, MINUS, BIG_SIGN_BIT);
  else
    set_bit(&value, PLUS, BIG_SIGN_BIT);
  copy(result, value);

  return OK;
}

int my_negate(my_decimal value, my_decimal *result) {
  int ret = OK;
  big_decimal val, res;
  from_dec_to_bigdec(value, &val);
  big_negate(val, &res);

  ret = from_bigdec_to_dec(res, result);

  return ret;
}