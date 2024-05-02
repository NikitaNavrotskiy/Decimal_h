#ifndef _MY_DECIMAL_H
#define _MY_DECIMAL_H

#include <math.h>
#include <stdint.h>

#define OK 0
#define TOO_LARGE 1
#define TOO_LOW 2
#define ZERO_DIV 3
#define MISSING_ACCUR 4

#define PLUS 0b00000000000000000000000000000000
#define MINUS 0b00000000000000000000000000000001

typedef struct {
  uint32_t bits[4];
} my_decimal;

#define MID_START 32
#define HIGHT_START 64
#define LOW_START 0
#define EXTRA_START 96
#define SIGN_BIT 127

typedef struct {
  uint32_t bits[8];
} big_decimal;

#define ZERO_START 0
#define FIRST_START 32
#define SECOND_START 64
#define THIRD_START 96
#define FOURTH_START 128
#define FIFTH_START 160
#define SIXTH_START 192
#define BIG_EXTRA_START 224
#define COUNT_OF_BITS 256
#define BIG_SIGN_BIT 255

int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result);
int big_add(big_decimal value_1, big_decimal value_2, big_decimal *result);

int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result);
int big_sub(big_decimal value_1, big_decimal value_2, big_decimal *result);

int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result);
int big_mul(big_decimal value_1, big_decimal value_2, big_decimal *result);

int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result);

// comparison

#define FALSE 0
#define TRUE 1

int my_is_less(my_decimal v1, my_decimal v2);
int big_is_less(big_decimal v1, big_decimal v2);

int my_is_less_or_equal(my_decimal v1, my_decimal v2);

int my_is_greater(my_decimal v1, my_decimal v2);
int big_is_greater(big_decimal v1, big_decimal v2);

int my_is_greater_or_equal(my_decimal v1, my_decimal v2);
int big_is_greater_or_equal(big_decimal v1, big_decimal v2);

int my_is_equal(my_decimal v1, my_decimal v2);
int big_is_equal(big_decimal v1, big_decimal v2);

int my_is_not_equal(my_decimal v1, my_decimal v2);

// converters

#define CONVERT_ERROR 1

int my_from_int_to_decimal(int src, my_decimal *dst);
int big_from_int_to_decimal(int src, big_decimal *dst);

int my_from_float_to_decimal(float src, my_decimal *dst);
int big_from_float_to_decimal(float src, big_decimal *dst);

int my_from_decimal_to_int(my_decimal src, int *dst);
int big_from_decimal_to_int(big_decimal src, int *dst);

int my_from_decimal_to_float(my_decimal src, float *dst);
int big_from_decimal_to_float(big_decimal src, float *dst);

// other

#define CALCULATE_ERROR 1

int my_floor(my_decimal value, my_decimal *result);
int big_floor(big_decimal value, big_decimal *result);

int my_round(my_decimal value, my_decimal *result);
int big_round(big_decimal value, big_decimal *result);

int my_truncate(my_decimal value, my_decimal *result);
int big_truncate(big_decimal value, big_decimal *result);

int my_negate(my_decimal value, my_decimal *result);
int big_negate(big_decimal value, big_decimal *result);

int get_bit(big_decimal value, int index);

int set_bit(big_decimal *value, int bit, int index);

int left_shift(big_decimal *value);

int right_shift(big_decimal *value);

int copy(big_decimal *dst, big_decimal src);

int get_scale(big_decimal value);

int set_scale(big_decimal *value, int scale);

int my_get_scale(my_decimal value);

int my_set_scale(my_decimal *value, int scale);

int my_set_bit(my_decimal *value, int bit, int index);

int set_all_null(big_decimal *value);

int from_bigdec_to_dec(big_decimal src, my_decimal *res);

int from_dec_to_bigdec(my_decimal src, big_decimal *res);

int add_same_scales(big_decimal value_1, big_decimal value_2,
                    big_decimal *result);

int sub_same_scales(big_decimal value_1, big_decimal value_2,
                    big_decimal *result);

int make_abs(big_decimal *value);

int mul_by_10(big_decimal *value);

int div_by_10(big_decimal *value);

int increase_scale(big_decimal *value, int shift);

int decrease_scale(big_decimal *value, int shift);

int make_scale_equal(big_decimal *value1, big_decimal *value2);

int _sum_with_overflow(int bit1, int bit2, int of_bit, int *new_of_bit);

int _sub_with_borrow(int bit1, int bit2, int borrow_cur_bit,
                     int *next_bit_borrow);

void normalize_float(float *num, int *scale);

#endif
