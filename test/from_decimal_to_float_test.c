#include "tests.h"

START_TEST(decimal_to_float_1) {
  float src = 5631345.0f;
  my_decimal src_d = {{5631345, 0, 0, 0}};
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_float_2) {
  float src = 3.31345f;
  my_decimal src_d = {{3313450, 0, 0, 0}};
  my_set_scale(&src_d, 6);
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_float_3) {
  float src = 3.313450f;
  my_decimal src_d = {{3313450, 0, 0, 0}};
  my_set_scale(&src_d, 6);
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_float_4) {
  float src = -0.0f;
  my_decimal src_d = {{0, 0, 0, 0}};
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_float_5) {
  float src = 33.13451f;
  my_decimal src_d = {{3313451, 0, 0, 0}};
  my_set_scale(&src_d, 5);
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_float_6) {
  float src = 331.3453f;
  my_decimal src_d = {{3313453, 0, 0, 0}};
  my_set_scale(&src_d, 4);
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_float_7) {
  float src = 9999.999f;
  my_decimal src_d = {{9999999, 0, 0, 0}};
  my_set_scale(&src_d, 3);
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_float_8) {
  float src = 88888.89f;
  my_decimal src_d = {{8888889, 0, 0, 0}};
  my_set_scale(&src_d, 2);

  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}

START_TEST(decimal_to_float_9) {
  float src = 82.52233f;
  my_decimal src_d = {{8252233, 0, 0, 0}};
  my_set_scale(&src_d, 5);
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_float_10) {
  float src = 88.89555f;
  my_decimal src_d = {{8889555, 0, 0, 0}};
  my_set_scale(&src_d, 5);
  float res;

  my_from_decimal_to_float(src_d, &res);

  ck_assert_int_eq(src == res, 1);
}

Suite *suite_my_decimal_to_float() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_from_decimal_to_float");
  tc = tcase_create("case_from_decimal_to_float");

  tcase_add_test(tc, decimal_to_float_1);
  tcase_add_test(tc, decimal_to_float_2);
  tcase_add_test(tc, decimal_to_float_3);
  tcase_add_test(tc, decimal_to_float_4);
  tcase_add_test(tc, decimal_to_float_5);
  tcase_add_test(tc, decimal_to_float_6);
  tcase_add_test(tc, decimal_to_float_7);
  tcase_add_test(tc, decimal_to_float_8);
  tcase_add_test(tc, decimal_to_float_9);
  tcase_add_test(tc, decimal_to_float_10);

  suite_add_tcase(s, tc);

  return s;
}