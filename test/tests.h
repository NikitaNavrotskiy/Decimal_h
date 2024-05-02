#ifndef _MY_DECIMAL_TESTS_H
#define _MY_DECIMAL_TESTS_H

#include <check.h>
#include <stdlib.h>
#include <time.h>

#include "../my_decimal.h"

Suite *suite_my_add();
Suite *suite_my_sub();
Suite *suite_my_mul();
Suite *suite_my_div();

Suite *suite_my_is_greater();
Suite *suite_my_is_greater_or_equal();
Suite *suite_my_is_less_or_equal();
Suite *suite_my_is_less();
Suite *suite_my_is_not_equal();
Suite *suite_my_is_equal();

Suite *suite_my_int_to_decimal();
Suite *suite_my_float_to_decimal();
Suite *suite_my_decimal_to_int();
Suite *suite_my_decimal_to_float();

Suite *suite_my_negate();

Suite *truncate_my_suite();
Suite *floor_my_suite();
Suite *round_my_suite();

void run_tests();
void run_one_test(Suite *test);

#endif