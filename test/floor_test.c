#include "tests.h"

START_TEST(floor_1) {
  my_decimal value_2;
  my_decimal value_1 = {{4, 0, 0, 0}};
  my_decimal result = {0};
  my_from_float_to_decimal(4.1111000, &value_2);
  int return_value = my_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(floor_2) {
  my_decimal value_2 = {0};
  my_decimal value_1 = {0};
  my_decimal result = {0};
  my_from_float_to_decimal(0.6111000, &value_2);
  int return_value = my_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(floor_3) {
  my_decimal value_2 = {0};
  my_decimal value_1 = {0};
  my_decimal result = {0};
  my_from_float_to_decimal(0.1111000, &value_2);
  int return_value = my_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(floor_4) {
  my_decimal value_2;
  my_decimal value_1;
  my_from_int_to_decimal(-5, &value_1);
  my_decimal result = {0};
  my_from_float_to_decimal(-4.1111000, &value_2);
  int return_value = my_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

Suite *floor_my_suite() {
  Suite *s = suite_create("floor_suite");
  TCase *tc = tcase_create("floor_testcase");

  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_4);

  suite_add_tcase(s, tc);
  return s;
}