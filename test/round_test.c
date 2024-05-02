#include "tests.h"

START_TEST(round_1) {
  my_decimal value_2 = {0};
  my_decimal result = {0};
  my_from_float_to_decimal(1.7111000, &value_2);
  int return_value = my_round(value_2, &result), result_int = 0;
  my_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, 2);
}
END_TEST

START_TEST(round_2) {
  my_decimal value_2 = {{15, 0, 0, 0x80010000}};
  my_decimal result = {0};
  int return_value = my_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(round_3) {
  my_decimal value_2 = {{0xFFFFFFFF, 0, 0xFFFFFFFF, 0x80020000}};
  my_decimal result = {0};
  int return_value = my_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(round_4) {
  my_decimal value_2 = {0};
  my_decimal result = {0};
  my_from_float_to_decimal(2.2, &value_2);
  int return_value = my_round(value_2, &result), result_int = 0;
  my_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, 2);
}
END_TEST

START_TEST(round_5) {
  my_decimal value_2 = {{15, 0, 0, pow(2, 16)}};
  my_decimal result = {0};
  int return_value = my_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

Suite *round_my_suite() {
  Suite *s = suite_create("round_suite");
  TCase *tc = tcase_create("round_testcase");

  tcase_add_test(tc, round_1);
  tcase_add_test(tc, round_2);
  tcase_add_test(tc, round_3);
  tcase_add_test(tc, round_4);
  tcase_add_test(tc, round_5);

  suite_add_tcase(s, tc);
  return s;
}