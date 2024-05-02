#include "tests.h"

START_TEST(my_sub_tests_1) {
  int a = 45;
  int b = 34;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}

START_TEST(my_sub_tests_2) {
  int a = 5531133;
  int b = -4113241;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}

START_TEST(my_sub_tests_3) {
  int a = -5531133;
  int b = 1132341;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}

START_TEST(my_sub_tests_4) {
  int a = -5133;
  int b = 6641;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}

START_TEST(my_sub_tests_5) {
  int a = -5531133;
  int b = 41132341;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}

START_TEST(my_sub_tests_6) {
  int a = -999999;
  int b = 999999;
  int c = 1234;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}

START_TEST(my_sub_tests_7) {
  int a = -45;
  int b = -34;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}

START_TEST(my_sub_tests_8) {
  int a = -5531133;
  int b = -41132341;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a - b, c);
}

START_TEST(my_sub_tests_9) {
  float a = 33134.50f;
  int b = 5503;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a - b, c, 0.000001);
}

START_TEST(my_sub_tests_10) {
  float b = 331345.3f;
  int a = 5503;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_int_to_decimal(a, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(b - a, c, 0.000001);
}

START_TEST(my_sub_tests_11) {
  float b = 3313.450f;
  float a = 5503.423f;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_float_to_decimal(a, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(b - a, c, 0.000001);
}

START_TEST(my_sub_tests_12) {
  float b = -0.13450f;
  float a = -0.234999f;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_float_to_decimal(a, &_b);
  my_sub(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(b - a, c, 0.000001);
}

Suite *suite_my_sub() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_sub");
  tc = tcase_create("case_sub");

  tcase_add_test(tc, my_sub_tests_1);
  tcase_add_test(tc, my_sub_tests_2);
  tcase_add_test(tc, my_sub_tests_3);
  tcase_add_test(tc, my_sub_tests_4);
  tcase_add_test(tc, my_sub_tests_5);
  tcase_add_test(tc, my_sub_tests_6);
  tcase_add_test(tc, my_sub_tests_7);
  tcase_add_test(tc, my_sub_tests_8);
  tcase_add_test(tc, my_sub_tests_9);
  tcase_add_test(tc, my_sub_tests_10);
  tcase_add_test(tc, my_sub_tests_11);
  tcase_add_test(tc, my_sub_tests_12);

  suite_add_tcase(s, tc);
  return s;
}