#include "my_decimal.h"

int big_is_greater(big_decimal v1, big_decimal v2) {
  int is_true = TRUE;
  int stop = 0;

  if (get_bit(v1, BIG_SIGN_BIT) == MINUS && get_bit(v2, BIG_SIGN_BIT) == PLUS)
    is_true = FALSE;
  else if (get_bit(v1, BIG_SIGN_BIT) == PLUS &&
           get_bit(v2, BIG_SIGN_BIT) == MINUS)
    is_true = TRUE;
  else {
    make_scale_equal(&v1, &v2);
    if (get_bit(v1, BIG_SIGN_BIT) == MINUS &&
        get_bit(v2, BIG_SIGN_BIT) == MINUS)
      for (int i = 6; i >= 0 && is_true && !stop; i--) {
        if (v1.bits[i] > v2.bits[i]) is_true = FALSE;
        if (v1.bits[i] < v2.bits[i]) {
          is_true = TRUE;
          stop = 1;
        }
      }
    else
      for (int i = 6; i >= 0 && is_true && !stop; i--) {
        if (v1.bits[i] < v2.bits[i]) is_true = FALSE;
        if (v1.bits[i] > v2.bits[i]) {
          is_true = TRUE;
          stop = 1;
        }
      }
  }

  return is_true && !big_is_equal(v1, v2);
}

int my_is_greater(my_decimal v1, my_decimal v2) {
  big_decimal val1, val2;
  from_dec_to_bigdec(v1, &val1);
  from_dec_to_bigdec(v2, &val2);

  return big_is_greater(val1, val2);
}