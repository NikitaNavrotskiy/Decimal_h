#include "tests.h"

START_TEST(my_mul_tests_1) {
  int a = 45;
  int b = 34;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a * b, c);
}

START_TEST(my_mul_tests_2) {
  int a = 5533;
  int b = -4241;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a * b, c);
}

START_TEST(my_mul_tests_3) {
  int a = -31133;
  int b = 141;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a * b, c);
}

START_TEST(my_mul_tests_4) {
  int a = -5133;
  int b = 6641;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a * b, c);
}

START_TEST(my_mul_tests_5) {
  int a = -3;
  int b = 2341;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a * b, c);
}

START_TEST(my_mul_tests_6) {
  int a = -9999;
  int b = -999;
  int c = 1234;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a * b, c);
}

START_TEST(my_mul_tests_7) {
  float a = 33134.50f;
  int b = 5503;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a * b, c, 0.001);
}

START_TEST(my_mul_tests_8) {
  float b = 331345.6f;
  int a = 5503;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_int_to_decimal(a, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a * b, c, 0.001);
}

START_TEST(my_mul_tests_9) {
  float b = 313.450f;
  int a = 503;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_int_to_decimal(a, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a * b, c, 0.1);
}

START_TEST(my_mul_tests_10) {
  float b = 345.3f;
  int a = 0;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_int_to_decimal(a, &_b);
  my_mul(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a * b, c, 0.00001);
}

Suite *suite_my_mul() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_mul");
  tc = tcase_create("case_mul");

  tcase_add_test(tc, my_mul_tests_1);
  tcase_add_test(tc, my_mul_tests_2);
  tcase_add_test(tc, my_mul_tests_3);
  tcase_add_test(tc, my_mul_tests_4);
  tcase_add_test(tc, my_mul_tests_5);
  tcase_add_test(tc, my_mul_tests_6);
  tcase_add_test(tc, my_mul_tests_7);
  tcase_add_test(tc, my_mul_tests_8);
  tcase_add_test(tc, my_mul_tests_9);
  tcase_add_test(tc, my_mul_tests_10);

  suite_add_tcase(s, tc);
  return s;
}
