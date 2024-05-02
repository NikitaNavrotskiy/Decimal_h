#include "tests.h"

START_TEST(my_div_tests_1) {
  int a = 0;
  int b = 10;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a / (float)b, c, 0.000001);
}

START_TEST(my_div_tests_2) {
  int a = 4200;
  int b = 42;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a / (float)b, c, 0.000001);
}

START_TEST(my_div_tests_3) {
  int a = 1470220;
  int b = 5548;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a / (float)b, c, 0.000001);
}

START_TEST(my_div_tests_4) {
  int a = 153942405;
  int b = 32145;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a / (float)b, c, 0.000001);
}

START_TEST(my_div_tests_5) {
  int b = 56;
  int a = 828016;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a / (float)b, c, 0.000001);
}

START_TEST(my_div_tests_6) {
  int a = -9990;
  int b = -999;
  float c = 1234;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a / (float)b, c, 0.000001);
}

START_TEST(my_div_tests_7) {
  float a = 6732.6f;
  float b = 1.4f;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  my_div(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a / (float)b, c, 0.000001);
}

Suite *suite_my_div() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_div");
  tc = tcase_create("case_div");

  tcase_add_test(tc, my_div_tests_1);
  tcase_add_test(tc, my_div_tests_2);
  tcase_add_test(tc, my_div_tests_3);
  tcase_add_test(tc, my_div_tests_4);
  tcase_add_test(tc, my_div_tests_5);
  tcase_add_test(tc, my_div_tests_6);
  tcase_add_test(tc, my_div_tests_7);

  suite_add_tcase(s, tc);
  return s;
}