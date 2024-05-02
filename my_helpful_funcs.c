#include "my_decimal.h"

int get_bit(big_decimal value, int index) {
  unsigned res = 0;

  unsigned mask = 1u << (index % 32);
  res = value.bits[index / 32] & mask;

  return res >> (index % 32);
}

int set_bit(big_decimal *value, int bit, int index) {
  unsigned mask = 1u << (index % 32);
  if (bit)
    value->bits[index / 32] |= mask;
  else
    value->bits[index / 32] &= ~mask;
  return OK;
}

int left_shift(big_decimal *value) {
  int res = OK;
  if (get_bit(*value, 95) == 1) res = TOO_LARGE;

  int tmp_0 = get_bit(*value, FIRST_START - 1);
  int tmp_1 = get_bit(*value, SECOND_START - 1);
  int tmp_2 = get_bit(*value, THIRD_START - 1);
  int tmp_3 = get_bit(*value, FOURTH_START - 1);
  int tmp_4 = get_bit(*value, FIFTH_START - 1);
  int tmp_5 = get_bit(*value, SIXTH_START - 1);

  for (int i = 0; i < 7; i++) value->bits[i] <<= 1;

  set_bit(value, tmp_0, FIRST_START);
  set_bit(value, tmp_1, SECOND_START);
  set_bit(value, tmp_2, THIRD_START);
  set_bit(value, tmp_3, FOURTH_START);
  set_bit(value, tmp_4, FIFTH_START);
  set_bit(value, tmp_5, SIXTH_START);

  return res;
}

int right_shift(big_decimal *value) {
  int tmp_0 = get_bit(*value, FIRST_START);
  int tmp_1 = get_bit(*value, SECOND_START);
  int tmp_2 = get_bit(*value, THIRD_START);
  int tmp_3 = get_bit(*value, FOURTH_START);
  int tmp_4 = get_bit(*value, FIFTH_START);
  int tmp_5 = get_bit(*value, SIXTH_START);

  for (int i = 0; i < 7; i++) value->bits[i] >>= 1;

  set_bit(value, tmp_0, FIRST_START - 1);
  set_bit(value, tmp_1, SECOND_START - 1);
  set_bit(value, tmp_2, THIRD_START - 1);
  set_bit(value, tmp_3, FOURTH_START - 1);
  set_bit(value, tmp_4, FIFTH_START - 1);
  set_bit(value, tmp_5, SIXTH_START - 1);
  return OK;
}

int copy(big_decimal *dst, big_decimal src) {
  for (int i = 0; i < COUNT_OF_BITS; i++) {
    set_bit(dst, get_bit(src, i), i);
  }
  return OK;
}

int get_scale(big_decimal value) {
  int res = 0;

  res = (value.bits[7] >> 16) & 0b11111111;

  return res;
}

int set_scale(big_decimal *value, int scale) {
  for (int i = BIG_EXTRA_START + 16; i < BIG_EXTRA_START + 23; i++) {
    set_bit(value, scale & 1, i);
    scale >>= 1;
  }

  return OK;
}

int my_get_scale(my_decimal value) {
  int res = 0;

  res = (value.bits[3] >> 16) & 0b11111111;

  return res;
}

int my_set_scale(my_decimal *value, int scale) {
  for (int i = EXTRA_START + 16; i < EXTRA_START + 23; i++) {
    my_set_bit(value, scale & 1, i);
    scale >>= 1;
  }

  return OK;
}

int my_set_bit(my_decimal *value, int bit, int index) {
  unsigned mask = 1u << (index % 32);
  if (bit)
    value->bits[index / 32] |= mask;
  else
    value->bits[index / 32] &= ~mask;
  return OK;
}

int set_all_null(big_decimal *value) {
  for (int i = 0; i < COUNT_OF_BITS; i++) set_bit(value, 0, i);
  return OK;
}

int from_bigdec_to_dec(big_decimal src, my_decimal *res) {
  int ret = OK;
  if (src.bits[4] || src.bits[5] || src.bits[6] || src.bits[3]) ret = TOO_LARGE;
  for (int i = 0; i < 3; i++) res->bits[i] = src.bits[i];
  res->bits[3] = src.bits[7];

  return ret;
}

int from_dec_to_bigdec(my_decimal src, big_decimal *res) {
  set_all_null(res);
  for (int i = 0; i < 3; i++) res->bits[i] = src.bits[i];
  res->bits[7] = src.bits[3];

  return OK;
}

int add_same_scales(big_decimal value_1, big_decimal value_2,
                    big_decimal *result) {
  int overflow = 0;
  int res = 0;

  int sign1 = get_bit(value_1, BIG_SIGN_BIT);
  int sign2 = get_bit(value_2, BIG_SIGN_BIT);

  if (sign1 == sign2) {
    for (int i = 0; i < 224; i++) {
      int bit1 = get_bit(value_1, i);
      int bit2 = get_bit(value_2, i);
      int sum = _sum_with_overflow(bit1, bit2, overflow, &overflow);
      set_bit(result, sum, i);
    }
    result->bits[7] = value_1.bits[7];
    if (sign1 == MINUS) set_bit(result, MINUS, BIG_SIGN_BIT);
  } else if (sign1 == MINUS && sign2 == PLUS) {
    big_negate(value_1, &value_1);
    res = sub_same_scales(value_2, value_1, result);
  } else {
    big_negate(value_2, &value_2);
    res = sub_same_scales(value_1, value_2, result);
  }
  set_scale(result, get_scale(value_1));

  return res;
}

int sub_same_scales(big_decimal value_1, big_decimal value_2,
                    big_decimal *result) {
  int res = 0;
  int borrow = 0;
  int final_sign = MINUS;
  int sign1 = get_bit(value_1, BIG_SIGN_BIT);
  int sign2 = get_bit(value_2, BIG_SIGN_BIT);

  big_decimal tmp1, tmp2, tmp3;
  copy(&tmp1, value_1);
  copy(&tmp2, value_2);
  make_abs(&tmp1);
  make_abs(&tmp2);

  if (sign1 == sign2) {
    if (sign1 == MINUS && sign2 == MINUS) {
      if (big_is_greater(tmp2, tmp1)) {
        final_sign = PLUS;
        tmp3 = value_1;
        value_1 = value_2;
        value_2 = tmp3;
      } else
        final_sign = MINUS;
    } else {
      if (big_is_greater(tmp2, tmp1)) {
        final_sign = MINUS;
        tmp3 = value_1;
        value_1 = value_2;
        value_2 = tmp3;
      } else
        final_sign = PLUS;
    }
    for (int i = 0; i < 224; i++) {
      int bit1 = get_bit(value_1, i);
      int bit2 = get_bit(value_2, i);
      int sub = _sub_with_borrow(bit1, bit2, borrow, &borrow);
      set_bit(result, sub, i);
    }
    res = OK;
    set_bit(result, final_sign, BIG_SIGN_BIT);
  } else {
    big_negate(value_2, &value_2);
    res = add_same_scales(value_1, value_2, result);
    if (sign1 == MINUS) set_bit(result, MINUS, BIG_SIGN_BIT);
  }
  set_scale(result, get_scale(value_1));
  return res;
}

int make_abs(big_decimal *value) {
  if (get_bit(*value, BIG_SIGN_BIT) == MINUS) big_negate(*value, value);

  return OK;
}

int mul_by_10(big_decimal *value) {
  int res = OK;
  int local_res = OK;
  big_decimal tmp1 = *value;
  big_decimal tmp2 = *value;

  local_res = left_shift(&tmp1);
  if (local_res != OK) res = TOO_LARGE;
  tmp2 = tmp1;
  local_res = left_shift(&tmp2);
  if (local_res != OK) res = TOO_LARGE;
  local_res = left_shift(&tmp2);
  if (local_res != OK) res = TOO_LARGE;

  add_same_scales(tmp2, tmp1, value);

  return res;
}

int div_by_10(big_decimal *value) {
  long long unsigned tmp = value->bits[2] % 10;
  value->bits[2] = (value->bits[2] - tmp) / 10;
  for (int i = 1; i >= 0; i--) {
    long long unsigned tmp1 =
        (long long unsigned)value->bits[i] + (tmp * pow(2, 32));
    tmp = tmp1 % 10;
    tmp1 -= tmp;
    value->bits[i] = tmp1 / 10;
  }
  value->bits[0] += tmp / 10;

  return OK;
}

int increase_scale(big_decimal *value, int shift) {
  int res = OK;
  int local_res = OK;

  local_res = set_scale(value, get_scale(*value) + shift);
  if (local_res != OK) res = local_res;

  for (int i = 0; i < shift; i++) {
    local_res = mul_by_10(value);
    if (local_res != OK) res = local_res;
  }

  return res;
}

int decrease_scale(big_decimal *value, int shift) {
  int res = OK;
  int scale = get_scale(*value);
  int j = 0;

  for (int i = 0; i < shift && get_scale(*value) >= 1; i++) {
    res = div_by_10(value);
    j++;
  }
  set_scale(value, scale - j);
  return res;
}

int make_scale_equal(big_decimal *value1, big_decimal *value2) {
  int res = OK;

  int scale1 = get_scale(*value1);
  int scale2 = get_scale(*value2);

  if (scale1 > scale2) {
    res = increase_scale(value2, scale1 - scale2);
  } else if (scale2 > scale1)
    res = increase_scale(value1, scale2 - scale1);
  return res;
}

int _sum_with_overflow(int bit1, int bit2, int of_bit, int *new_of_bit) {
  int res = 0;
  *new_of_bit = bit1 & bit2;
  if (!*new_of_bit && of_bit && (bit1 || bit2)) *new_of_bit = 1;
  res = bit1 ^ bit2 ^ of_bit;
  return res;
}

int _sub_with_borrow(int bit1, int bit2, int borrow_cur_bit,
                     int *next_bit_borrow) {
  int res = 0;
  if (bit1 && bit2 && !borrow_cur_bit) {
    *next_bit_borrow = 0;
    res = 0;
  } else if (bit1 && bit2 && borrow_cur_bit) {
    *next_bit_borrow = 1;
    res = 1;
  } else if (bit1 && !bit2 && !borrow_cur_bit) {
    res = 1;
    *next_bit_borrow = 0;
  } else if (bit1 && !bit2 && borrow_cur_bit) {
    *next_bit_borrow = 0;
    res = 0;
  } else if (!bit1 && bit2 && !borrow_cur_bit) {
    res = 1;
    *next_bit_borrow = 1;
  } else if (!bit1 && !bit2 && borrow_cur_bit) {
    *next_bit_borrow = 1;
    res = 1;
  } else if (!bit1 && bit2 && borrow_cur_bit) {
    *next_bit_borrow = 1;
    res = 0;
  } else if (!bit1 && !bit2 && !borrow_cur_bit) {
    res = 0;
    *next_bit_borrow = 0;
  }

  return res;
}

void normalize_float(float *num, int *scale) {
  int new_scale = *scale;
  while (!(int)*num || !(int)(*num / 1000000)) {
    *num *= 10;
    new_scale++;
  }
  *num = roundf(*num);
  while (new_scale && !((int)*num % 10)) {
    *num /= 10;
    new_scale--;
  }
  *scale = new_scale;
}