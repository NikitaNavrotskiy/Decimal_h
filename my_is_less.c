#include "my_decimal.h"

int big_is_less(big_decimal v1, big_decimal v2) {
  return !big_is_greater(v1, v2) && !big_is_equal(v1, v2);
}

int my_is_less(my_decimal v1, my_decimal v2) {
  return !my_is_greater(v1, v2) && !my_is_equal(v1, v2);
}