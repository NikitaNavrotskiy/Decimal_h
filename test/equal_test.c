#include "tests.h"

START_TEST(my_is_equal_test_1) {
  float a = -10114.242;
  float b = -10114.242;

  my_decimal _a;
  my_decimal _b;
  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}
END_TEST

START_TEST(my_is_equal_test_2) {
  float a = 124.1;
  float b = -0.02424;

  my_decimal _a;
  my_decimal _b;
  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}
END_TEST

START_TEST(my_is_equal_test_3) {
  float a = 25.158531;
  float b = -39.425785;

  my_decimal _a;
  my_decimal _b;
  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_4) {
  float a = 25.158531;
  float b = 39.425785;

  my_decimal _a;
  my_decimal _b;
  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_5) {
  float a = 0.0;
  float b = 0.0;

  my_decimal _a;
  my_decimal _b;
  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_6) {
  float a = 0.15853;
  float b = 0.15852;

  my_decimal _a;
  my_decimal _b;
  my_from_float_to_decimal(a, &_a);
  my_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_7) {
  int a = 245564;
  int b = 1425242;

  my_decimal _a;
  my_decimal _b;
  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_8) {
  int a = 1234567;
  int b = 1234567;

  my_decimal _a;
  my_decimal _b;
  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_9) {
  int a = -1234567;
  int b = -1234567;

  my_decimal _a;
  my_decimal _b;
  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_10) {
  int a = 1;
  int b = -1123241;

  my_decimal _a;
  my_decimal _b;
  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_11) {
  int a = -1123241;
  int b = 1;

  my_decimal _a;
  my_decimal _b;
  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_12) {
  int a = 2;
  int b = 1;

  my_decimal _a;
  my_decimal _b;
  my_from_int_to_decimal(a, &_a);
  my_from_int_to_decimal(b, &_b);
  ck_assert_int_eq(my_is_equal(_a, _b), a == b);
}

START_TEST(my_is_equal_test_13) {
  my_decimal _a = {{0b10000000000000000000000000000000, 1231, 4321, 2442}};
  my_decimal _b = {{0b10000000000000000000000000000000, 1234, 4321, 2442}};
  ck_assert_int_eq(my_is_equal(_a, _b), 0);
}

START_TEST(my_is_equal_test_14) {
  my_decimal _a = {
      {0b00000000000000000000000000000000, __INT32_MAX__ - 1, 4321, 2442}};
  my_decimal _b = {
      {0b00000000000000000000000000000000, __INT32_MAX__, 4321, 2442}};
  ck_assert_int_eq(my_is_equal(_a, _b), 0);
}

START_TEST(my_is_equal_test_15) {
  my_decimal _a = {{0b00000000000000000000000000000000, __INT32_MAX__,
                     __INT32_MAX__, __INT32_MAX__}};
  my_decimal _b = {{0b00000000000000000000000000000000, __INT32_MAX__,
                     __INT32_MAX__, __INT32_MAX__}};
  ck_assert_int_eq(my_is_equal(_a, _b), 1);
}

Suite *suite_my_is_equal() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_is_equal");
  tc = tcase_create("case_is_equal");

  tcase_add_test(tc, my_is_equal_test_1);
  tcase_add_test(tc, my_is_equal_test_2);
  tcase_add_test(tc, my_is_equal_test_3);
  tcase_add_test(tc, my_is_equal_test_4);
  tcase_add_test(tc, my_is_equal_test_5);
  tcase_add_test(tc, my_is_equal_test_6);
  tcase_add_test(tc, my_is_equal_test_7);
  tcase_add_test(tc, my_is_equal_test_8);
  tcase_add_test(tc, my_is_equal_test_9);
  tcase_add_test(tc, my_is_equal_test_10);
  tcase_add_test(tc, my_is_equal_test_11);
  tcase_add_test(tc, my_is_equal_test_12);
  tcase_add_test(tc, my_is_equal_test_13);
  tcase_add_test(tc, my_is_equal_test_14);
  tcase_add_test(tc, my_is_equal_test_15);

  suite_add_tcase(s, tc);

  return s;
}