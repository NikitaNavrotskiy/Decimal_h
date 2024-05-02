#include "tests.h"

START_TEST(int_to_decimal_1) {
  int src = INT32_MAX;
  my_decimal exp = {{INT32_MAX, 0, 0, 0}};
  my_decimal res;

  my_from_int_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0] == exp.bits[0] && res.bits[3] == exp.bits[3], 1);
}
END_TEST

START_TEST(int_to_decimal_2) {
  int src = INT32_MIN;
  my_decimal exp = {{INT32_MIN, 0, 0, 0b10000000000000000000000000000000}};
  my_decimal res;

  my_from_int_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0] == exp.bits[0] && res.bits[3] == exp.bits[3], 1);
}
END_TEST

START_TEST(int_to_decimal_3) {
  int src = rand();
  my_decimal exp = {{src, 0, 0, 0}};
  my_decimal res;

  my_from_int_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0] == exp.bits[0] && res.bits[3] == exp.bits[3], 1);
}
END_TEST

START_TEST(int_to_decimal_4) {
  int src = -rand();
  my_decimal exp = {{-src, 0, 0, 0b10000000000000000000000000000000}};
  my_decimal res;

  my_from_int_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0] == exp.bits[0] && res.bits[3] == exp.bits[3], 1);
}
END_TEST

Suite *suite_my_int_to_decimal() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_from_int_to_decimal");
  tc = tcase_create("case_from_int_to_decimal");

  tcase_add_test(tc, int_to_decimal_1);
  tcase_add_test(tc, int_to_decimal_2);
  tcase_add_loop_test(tc, int_to_decimal_3, 0, 14);
  tcase_add_loop_test(tc, int_to_decimal_4, 0, 14);

  suite_add_tcase(s, tc);

  return s;
}