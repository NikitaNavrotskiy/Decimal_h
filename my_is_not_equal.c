#include "my_decimal.h"

int my_is_not_equal(my_decimal v1, my_decimal v2) {
  return !my_is_equal(v1, v2);
};