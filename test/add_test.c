#include "tests.h"

START_TEST(my_add_tests_1) {
  int a = 45;
  int b = 34;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}

START_TEST(my_add_tests_2) {
  int a = 5531133;
  int b = -4113241;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}

START_TEST(my_add_tests_3) {
  int a = -5531133;
  int b = 1132341;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}

START_TEST(my_add_tests_4) {
  int a = -5133;
  int b = 6641;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}

START_TEST(my_add_tests_5) {
  int a = -5531133;
  int b = 41132341;
  int c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}

START_TEST(my_add_tests_6) {
  int a = -999999;
  int b = 999999;
  int c = 1234;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_int(res, &c);

  ck_assert_int_eq(a + b, c);
}

START_TEST(my_add_tests_7) {
  float a = 33134.50f;
  int b = 5503;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a + b, c, 0.000001);
}

START_TEST(my_add_tests_8) {
  float b = 3315.230f;
  int a = 5503;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_int_to_decimal(a, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a + b, c, 0.000001);
}

START_TEST(my_add_tests_9) {
  float b = 3313.450f;
  float a = 5503.423f;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_float_to_decimal(a, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a + b, c, 0.0001);
}

START_TEST(my_add_tests_10) {
  float b = 331345.8f;
  float a = -550342.3f;
  float c = 0;

  my_decimal _a;
  my_decimal _b;
  my_decimal res;

  my_from_float_to_decimal(b, &_a);
  my_from_float_to_decimal(a, &_b);
  my_add(_a, _b, &res);
  my_from_decimal_to_float(res, &c);

  ck_assert_float_eq_tol(a + b, c, 0.1);
}

Suite *suite_my_add() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_add");
  tc = tcase_create("case_add");

  tcase_add_test(tc, my_add_tests_1);
  tcase_add_test(tc, my_add_tests_2);
  tcase_add_test(tc, my_add_tests_3);
  tcase_add_test(tc, my_add_tests_4);
  tcase_add_test(tc, my_add_tests_5);
  tcase_add_test(tc, my_add_tests_6);
  tcase_add_test(tc, my_add_tests_7);
  tcase_add_test(tc, my_add_tests_8);
  tcase_add_test(tc, my_add_tests_9);
  tcase_add_test(tc, my_add_tests_10);

  suite_add_tcase(s, tc);
  return s;
}
