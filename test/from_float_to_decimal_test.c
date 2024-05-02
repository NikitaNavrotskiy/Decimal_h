#include "tests.h"

START_TEST(float_to_decimal_1) {
  float src = 5631.340f;
  my_decimal exp = {{563134, 0, 0, 0}};
  my_decimal res;
  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}
END_TEST

START_TEST(float_to_decimal_2) {
  float src = -3.31345f;
  my_decimal exp = {{331345, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}
END_TEST

START_TEST(float_to_decimal_3) {
  float src = 3.313450f;
  my_decimal exp = {{331345, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}
END_TEST

START_TEST(float_to_decimal_4) {
  float src = -0.0f;
  my_decimal exp = {{0, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}
END_TEST

START_TEST(float_to_decimal_5) {
  float src = 33.13451f;
  my_decimal exp = {{3313451, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}
END_TEST

START_TEST(float_to_decimal_6) {
  float src = 331.3453f;
  my_decimal exp = {{3313453, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}
END_TEST

START_TEST(float_to_decimal_7) {
  float src = 9999.999f;
  my_decimal exp = {{9999999, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}
END_TEST

START_TEST(float_to_decimal_8) {
  float src = 88888.89f;
  my_decimal exp = {{8888889, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}

START_TEST(float_to_decimal_9) {
  float src = 82.52231f;
  my_decimal exp = {{8252231, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}
END_TEST

START_TEST(float_to_decimal_10) {
  float src = 88.8955f;
  my_decimal exp = {{888955, 0, 0, 0}};
  my_decimal res;

  my_from_float_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0], exp.bits[0]);
}

Suite *suite_my_float_to_decimal() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_from_float_to_decimal");
  tc = tcase_create("case_from_float_to_decimal");

  tcase_add_test(tc, float_to_decimal_1);
  tcase_add_test(tc, float_to_decimal_2);
  tcase_add_test(tc, float_to_decimal_3);
  tcase_add_test(tc, float_to_decimal_4);
  tcase_add_test(tc, float_to_decimal_5);
  tcase_add_test(tc, float_to_decimal_6);
  tcase_add_test(tc, float_to_decimal_7);
  tcase_add_test(tc, float_to_decimal_8);
  tcase_add_test(tc, float_to_decimal_9);
  tcase_add_test(tc, float_to_decimal_10);

  suite_add_tcase(s, tc);

  return s;
}