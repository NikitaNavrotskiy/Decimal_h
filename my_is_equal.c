#include "my_decimal.h"

int big_is_equal(big_decimal v1, big_decimal v2) {
  int is_equal = TRUE;
  make_scale_equal(&v1, &v2);

  for (int i = 0; i < 7 && is_equal; i++) {
    if (v1.bits[i] != v2.bits[i]) is_equal = FALSE;
  }

  return is_equal;
}

int my_is_equal(my_decimal v1, my_decimal v2) {
  int is_equal = OK;
  big_decimal val1, val2;
  from_dec_to_bigdec(v1, &val1);
  from_dec_to_bigdec(v2, &val2);

  is_equal = big_is_equal(val1, val2);

  return is_equal;
}

/* #include <stdio.h>
int main()
{
    my_decimal a = {{1, 0, 0, 0}};
    my_decimal b = {{2, 0, 0, 0}};
    my_decimal res;
    my_is_equal(a, b);
    printf("%d", my_is_equal(a, b));
} */