#include "tests.h"

START_TEST(truncate_1) {
  my_decimal value_2 = {0};
  my_decimal value_1 = {{4, 0, 0, 0}};
  my_decimal result = {0};
  my_from_float_to_decimal(4.1111000, &value_2);
  int return_value = my_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(truncate_2) {
  my_decimal value_2 = {0};
  my_decimal value_1 = {0};
  my_decimal result = {0};
  my_from_float_to_decimal(0.1111000, &value_2);
  int return_value = my_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(truncate_3) {
  my_decimal value_2 = {0};
  my_decimal value_1 = {0};
  my_from_int_to_decimal(-4, &value_1);
  my_decimal result = {0};
  my_from_float_to_decimal(-4.1124323, &value_2);
  int return_value = my_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(truncate_4) {
  my_decimal value_2 = {0};
  my_decimal value_1 = {0};
  my_decimal result = {0};
  my_from_float_to_decimal(-0.1111000, &value_2);
  int return_value = my_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(truncate_5) {
  my_decimal value_2 = {0};
  my_decimal value_1 = {{34, 0, 0, 0}};
  my_decimal result = {0};
  my_from_int_to_decimal(34, &value_2);
  int return_value = my_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(my_is_equal(result, value_1), 1);
}
END_TEST

Suite *truncate_my_suite() {
  Suite *s = suite_create("truncate_suite");
  TCase *tc = tcase_create("truncate_testcase");

  tcase_add_test(tc, truncate_1);
  tcase_add_test(tc, truncate_2);
  tcase_add_test(tc, truncate_3);
  tcase_add_test(tc, truncate_4);
  tcase_add_test(tc, truncate_5);

  suite_add_tcase(s, tc);
  return s;
}