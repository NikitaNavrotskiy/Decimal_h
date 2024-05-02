#include "my_decimal.h"

int my_is_less_or_equal(my_decimal v1, my_decimal v2) {
  return my_is_less(v1, v2) || my_is_equal(v1, v2);
}