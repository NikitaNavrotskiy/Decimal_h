#include "tests.h"

START_TEST(my_negate_tests_1) {
  my_decimal pos = {{0, 0, 0, 0}};
  my_decimal exp = {{0, 0, 0, 0b10000000000000000000000000000000}};
  my_decimal res;
  my_negate(pos, &res);

  ck_assert_int_eq(my_is_equal(exp, res), 1);
}

START_TEST(my_negate_tests_2) {
  int a = 455553;
  my_decimal pos, exp, res;
  my_from_int_to_decimal(a, &pos);
  my_from_int_to_decimal(-a, &exp);

  my_negate(pos, &res);

  ck_assert_int_eq(my_is_equal(exp, res), 1);
}

START_TEST(my_negate_tests_3) {
  int a = INT32_MAX;
  my_decimal pos, exp, res;
  my_from_int_to_decimal(a, &pos);
  my_from_int_to_decimal(-a, &exp);

  my_negate(pos, &res);

  ck_assert_int_eq(my_is_equal(exp, res), 1);
}

START_TEST(my_negate_tests_4) {
  int a = INT32_MIN + 1;
  my_decimal pos, exp, res;
  my_from_int_to_decimal(a, &pos);
  my_from_int_to_decimal(-a, &exp);

  my_negate(pos, &res);

  ck_assert_int_eq(my_is_equal(exp, res), 1);
}

START_TEST(my_negate_tests_5) {
  int a = -455553;
  my_decimal pos, exp, res;
  my_from_int_to_decimal(a, &pos);
  my_from_int_to_decimal(-a, &exp);

  my_negate(pos, &res);

  ck_assert_int_eq(my_is_equal(exp, res), 1);
}

START_TEST(my_negate_tests_6) {
  float a = 3.313450f;
  my_decimal exp, res, pos;
  my_from_float_to_decimal(a, &exp);
  my_set_bit(&exp, MINUS, SIGN_BIT);
  my_from_float_to_decimal(a, &pos);
  my_negate(pos, &res);
  ck_assert_int_eq(my_is_equal(res, exp), 1);
}

START_TEST(my_negate_tests_7) {
  float a = 3313450.0f;
  my_decimal exp, res, pos;
  my_from_float_to_decimal(a, &exp);
  my_set_bit(&exp, MINUS, SIGN_BIT);
  my_from_float_to_decimal(a, &pos);
  my_negate(pos, &res);
  ck_assert_int_eq(my_is_equal(res, exp), 1);
}

START_TEST(my_negate_tests_8) {
  float a = 331345.5f;
  my_decimal exp, res, pos;
  my_from_float_to_decimal(a, &exp);
  my_set_bit(&exp, MINUS, SIGN_BIT);
  my_from_float_to_decimal(a, &pos);
  my_negate(pos, &res);
  ck_assert_int_eq(my_is_equal(res, exp), 1);
}

START_TEST(my_negate_tests_9) {
  float a = -3313450.0f;
  my_decimal exp, res, pos;
  my_from_float_to_decimal(a, &exp);
  my_set_bit(&exp, MINUS, SIGN_BIT);
  my_from_float_to_decimal(a, &pos);
  my_negate(pos, &res);
  ck_assert_int_eq(my_is_equal(res, exp), 1);
}

START_TEST(my_negate_tests_10) {
  float a = -331345.5f;
  my_decimal exp, res, pos;
  my_from_float_to_decimal(a, &exp);
  my_set_bit(&exp, MINUS, SIGN_BIT);
  my_from_float_to_decimal(a, &pos);
  my_negate(pos, &res);
  ck_assert_int_eq(my_is_equal(res, exp), 1);
}

Suite *suite_my_negate() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_negate");
  tc = tcase_create("case_negate");

  tcase_add_test(tc, my_negate_tests_1);
  tcase_add_test(tc, my_negate_tests_2);
  tcase_add_test(tc, my_negate_tests_3);
  tcase_add_test(tc, my_negate_tests_4);
  tcase_add_test(tc, my_negate_tests_5);
  tcase_add_test(tc, my_negate_tests_6);
  tcase_add_test(tc, my_negate_tests_7);
  tcase_add_test(tc, my_negate_tests_8);
  tcase_add_test(tc, my_negate_tests_9);
  tcase_add_test(tc, my_negate_tests_10);
  suite_add_tcase(s, tc);
  return s;
}