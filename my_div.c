#include <stdlib.h>

#include "my_decimal.h"

int _check_can_mul_10(big_decimal value) {
  int res = 1;
  long int num = (long int)value.bits[3];
  if (num * 10 > 0b01111111111111111111111111111111) res = 0;
  return res;
}

int _is_less_for_div(big_decimal val1, big_decimal val2, big_decimal tmp,
                     big_decimal *part_of_res, big_decimal *new_val1) {
  int ret = 0;
  big_decimal res = {0}, tmp_copy = {0};
  copy(&tmp_copy, tmp);
  big_mul(tmp, val2, &res);

  if (big_is_greater(res, val1)) {
    ret = 1;
    right_shift(&tmp_copy);
    right_shift(&res);
    *part_of_res = tmp_copy;
    big_sub(val1, res, new_val1);
  } else
    part_of_res = NULL;

  return ret;
}

int _zero_div_check(big_decimal val) {
  int err = ZERO_DIV;
  for (int i = 0; i < 224 && err == ZERO_DIV; i++) {
    if (get_bit(val, i) == 1) err = OK;
  }
  return err;
}

int _end_of_division(big_decimal *result, int res_scale, int sign1, int sign2) {
  if (res_scale > 0)
    set_scale(result, res_scale);
  else {
    res_scale = -res_scale;
    for (int i = 0; i < res_scale; i++) mul_by_10(result);
  }
  if (sign1 != sign2) set_bit(result, MINUS, BIG_SIGN_BIT);

  return OK;
}

int _process_division(big_decimal value_1, big_decimal value_2,
                      big_decimal *result, int old_scale, int *res_scale) {
  int count = 0;
  int flag = 1;
  big_decimal part_res;
  set_all_null(result);
  while (big_is_less(value_1, value_2)) {
    mul_by_10(&value_1);
    count++;
  }

  while (flag && _zero_div_check(value_1) == OK && count < 26) {
    big_decimal tmp = {{1, 0, 0, 0, 0, 0, 0, 0}};
    while (!_is_less_for_div(value_1, value_2, tmp, &part_res, &value_1))
      left_shift(&tmp);
    big_add(*result, part_res, result);
    if (big_is_less(value_1, value_2) && _zero_div_check(value_1) == OK &&
        _check_can_mul_10(*result)) {
      mul_by_10(&value_1);
      mul_by_10(result);
      count++;
    }
    if (_zero_div_check(value_1) != OK && !_check_can_mul_10(*result)) flag = 0;
  }

  *res_scale = old_scale + count;

  return OK;
}

int big_div(big_decimal value_1, big_decimal value_2, big_decimal *result) {
  int err = OK;
  int res_proc_scale = 0;
  err = _zero_div_check(value_2);
  big_decimal res;
  int sign1 = get_bit(value_1, BIG_SIGN_BIT),
      sign2 = get_bit(value_2, BIG_SIGN_BIT);
  int res_scale = get_scale(value_1) - get_scale(value_2);
  set_bit(&value_1, PLUS, BIG_SIGN_BIT);
  set_bit(&value_2, PLUS, BIG_SIGN_BIT);
  set_scale(&value_1, 0);
  set_scale(&value_2, 0);
  _process_division(value_1, value_2, &res, res_scale, &res_proc_scale);
  err = _end_of_division(&res, res_proc_scale, sign1, sign2);

  *result = res;

  return err;
}

int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int ret = OK;
  big_decimal val1, val2, res;
  from_dec_to_bigdec(value_1, &val1);
  from_dec_to_bigdec(value_2, &val2);
  if (_zero_div_check(val2) != OK) {
    set_all_null(&res);
    from_bigdec_to_dec(res, result);
    return ZERO_DIV;
  } else if (_zero_div_check(val1) != OK) {
    set_all_null(&res);
    from_bigdec_to_dec(res, result);
    return OK;
  }
  big_div(val1, val2, &res);

  if (res.bits[3] || res.bits[4] || res.bits[5] || res.bits[7])
    ret = TOO_LARGE;
  else
    from_bigdec_to_dec(res, result);
  return ret;
}

/* #include <stdio.h>
int main()
{

    float a = 242.3f;
    float b = 10.4f;
    float r;
    my_decimal _a, _b, res;
    my_from_float_to_decimal(a, &_a);
    my_from_float_to_decimal(b, &_b);
    my_div(_a, _b, &res);
    my_from_decimal_to_float(res, &r);

    printf("%f  %f", a/(float)b, r);
} */
