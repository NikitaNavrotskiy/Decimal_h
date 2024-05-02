#include "tests.h"

int main() {
  run_tests();
  return 0;
}

void run_tests() {
  srand(time(NULL));

  Suite *list[] = {suite_my_add(),
                   suite_my_sub(),
                   suite_my_mul(),
                   suite_my_div(),
                   suite_my_is_greater(),
                   suite_my_is_greater_or_equal(),
                   suite_my_is_less_or_equal(),
                   suite_my_is_less(),
                   suite_my_is_equal(),
                   suite_my_is_not_equal(),
                   suite_my_int_to_decimal(),
                   suite_my_float_to_decimal(),
                   suite_my_decimal_to_int(),
                   suite_my_decimal_to_float(),
                   suite_my_negate(),
                   truncate_my_suite(),
                   floor_my_suite(),
                   round_my_suite(),
                   NULL};

  for (Suite **cur = list; *cur; cur++) run_one_test(*cur);
}

void run_one_test(Suite *test) {
  SRunner *sr = srunner_create(test);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}