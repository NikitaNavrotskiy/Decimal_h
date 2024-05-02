#include "tests.h"

START_TEST(decimal_to_int_1) {
  int src = INT32_MIN + 1;
  int res;
  my_decimal src_d = {{-src, 0, 0, 0b10000000000000000000000000000000}};

  my_from_decimal_to_int(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_int_2) {
  int src = INT32_MIN;
  my_decimal exp = {{INT32_MIN, 0, 0, 0b10000000000000000000000000000000}};
  my_decimal res;

  my_from_int_to_decimal(src, &res);

  ck_assert_int_eq(res.bits[0] == exp.bits[0] && res.bits[3] == exp.bits[3], 1);
}
END_TEST

START_TEST(decimal_to_int_3) {
  int src = rand();
  int res;
  my_decimal src_d = {{src, 0, 0, 0}};

  my_from_decimal_to_int(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

START_TEST(decimal_to_int_4) {
  int src = -rand();
  int res;
  my_decimal src_d = {{-src, 0, 0, 0b10000000000000000000000000000000}};

  my_from_decimal_to_int(src_d, &res);

  ck_assert_int_eq(res == src, 1);
}
END_TEST

Suite *suite_my_decimal_to_int() {
  Suite *s;
  TCase *tc;
  s = suite_create("my_from_decimal_to_int");
  tc = tcase_create("case_from_decimal_to_int");

  tcase_add_test(tc, decimal_to_int_1);
  tcase_add_test(tc, decimal_to_int_2);
  tcase_add_loop_test(tc, decimal_to_int_3, 0, 14);
  tcase_add_loop_test(tc, decimal_to_int_4, 0, 14);

  suite_add_tcase(s, tc);

  return s;
}