
#include "s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int big_decimal_add(big_decimal value_1, big_decimal value_2,
                    big_decimal *result);
int big_decimal_sub(big_decimal value_1, big_decimal value_2,
                    big_decimal *result);
int big_decimal_is_greater(big_decimal value1, big_decimal value2);
int print_decimal(s21_decimal dcml_1);

big_decimal from_decimal_to_big_decimal(s21_decimal dec);
s21_decimal from_big_decimal_to_decimal(big_decimal dec);

int GetExponent(s21_decimal dcml);
int SetExponent(s21_decimal *dcml, int exp);
int DecimalShift(s21_decimal *dcml, int shift);
int s21_mul_mantissa(s21_decimal dcml_1, s21_decimal dcml_2,
                     big_decimal *result);

int get_bite_from_decimal(s21_decimal dec, int number);
void clear_decimal(s21_decimal *dst);
int check_for_one(big_decimal dec);

//------------------------------------------------------------------
// Операции с большими децималами
//------------------------------------------------------------------

int get_bite_from_big_decimal(big_decimal dec, int position) {
  int return_value = 0;
  int bits = 0;

  bits = position / 32;
  position %= 32;

  if (1 << position & dec.bits[bits]) {
    return_value = 1;
  }

  return return_value;
}

int SetBit(s21_decimal *value_1, int position, int bit) {
  short int EXIT_CODE = 0;
  short int numOfBit = 0;
  numOfBit = (position / 32);
  position = (position - (32 * numOfBit));
  if (position > 127) {
    EXIT_CODE = 1;
  }
  if (bit && !EXIT_CODE) {
    value_1->bits[numOfBit] |= (1 << position);
  } else {
    value_1->bits[numOfBit] &= ~(1 << position);
  }
  return EXIT_CODE;
}

/**
 *Функция получает на вход decimal, если находит в мантисе 1,
 *то возвращает 1, в противном случае, возвращает 0
 */

int check_for_one(big_decimal dec) {
  int return_value = 0;

  for (int i = 0; i < 192; i++) {
    if (get_bite_from_big_decimal(dec, i)) {
      return_value = 1;
      break;
    }
  }

  return return_value;
}

// void print_big_decimal(big_decimal src) {
//   for (int i = 223; i >= 0; i--) {
//     printf("%d", get_bite_from_big_decimal(src, i));
//     if (i % 32 == 0) {
//       printf(" = %d\n", i / 32);
//       //       printf("\n");
//     }
//   }
// }

void change_big_decimal_bit(big_decimal *dec, int bit, int position) {
  int bits = position / 32;
  position %= 32;

  if (bit) {
    dec->bits[bits] |= (1 << position);
  } else {
    dec->bits[bits] &= ~(1 << position);
  }
}

void clear_big_decimal(big_decimal *dst) {
  for (int i = 0; i < 7; i++) {
    dst->bits[i] = 0;
  }
}

void equation_big_decimal(big_decimal dec, big_decimal *buf) {
  int bits = 0;
  for (int i = 0; i < 224; i++) {
    if (i % 32 == 0 && i / 32 != 0) {
      bits += 1;
    }

    if (get_bite_from_big_decimal(dec, i)) {
      buf->bits[bits] |= (1 << i % 32);
    } else {
      buf->bits[bits] &= ~(1 << i % 32);
    }
  }
}

int get_big_decimal_exp(big_decimal dec) {
  int exp = 0;

  for (int i = 16; i < 24; i++) {
    exp += pow(2, i - 16) * get_bite_from_big_decimal(dec, i + 192);
  }

  return exp;
}

int set_big_decimal_exp(big_decimal *dec, int exp) {
  int EXIT_CODE = 0;
  if (exp > 28) {
    EXIT_CODE = 1;
  }
  if (!EXIT_CODE) {
    int bitmask = 0b11111111;
    bitmask = bitmask << 16;
    dec->bits[6] &= ~bitmask;
    dec->bits[6] |= exp << 16;
  }
  return EXIT_CODE;
}

void multiply_big_decimal_by_ten(big_decimal *dec) {
  big_decimal buf = {{0, 0, 0, 0, 0, 0, 0}};
  int buf_bit = 0;
  int add_value = 0;
  int bit1 = 0, bit2 = 0;
  equation_big_decimal(*dec, &buf);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 192; j++) {
      bit1 = get_bite_from_big_decimal(buf, j);
      bit2 = get_bite_from_big_decimal(*dec, j);

      add_value = (buf_bit + bit1 + bit2) % 2;
      buf_bit = (buf_bit + bit1 + bit2) / 2;

      change_big_decimal_bit(dec, add_value, j);
    }
    buf_bit = 0;
  }
  buf_bit = 1;
  for (int i = 16; i < 24; i++) {
    bit2 = get_bite_from_big_decimal(*dec, i + 192);

    add_value = (buf_bit + bit2) % 2;
    buf_bit = (buf_bit + bit2) / 2;
    change_big_decimal_bit(dec, add_value, i + 192);
  }
}

void equal_big_decimal_exp(big_decimal *value_1, big_decimal *value_2) {
  int exp1 = get_big_decimal_exp(*value_1);
  int exp2 = get_big_decimal_exp(*value_2);

  if (exp1 - exp2 < 0) {
    for (int i = 0; i < exp2 - exp1; i++) {
      multiply_big_decimal_by_ten(value_1);
    }
  } else if (exp2 - exp1 < 0) {
    for (int i = 0; i < exp1 - exp2; i++) {
      multiply_big_decimal_by_ten(value_2);
    }
  }
}

int DecimalShiftRight_big_decimal(big_decimal *dcml, int shift) {
  int EXIT_CODE = 0;
  int bit = 0;
  for (int i = 0; i < shift; i++) {
    bit = get_bite_from_big_decimal(*dcml, i);
    if (bit) {
      EXIT_CODE = 1;
      break;
    }
  }
  for (int i = 0; i < 192; i++) {
    bit = get_bite_from_big_decimal(*dcml, i);
    if (bit) {
      change_big_decimal_bit(dcml, bit, i - shift);
      change_big_decimal_bit(dcml, 0, i);
    }
  }

  return EXIT_CODE;
}

int DecimalShift_big_decimal(big_decimal *dcml, int shift) {
  int bit = 0;
  int EXIT_CODE = 0;
  // check if there is space for shift
  if (get_bite_from_big_decimal(*dcml, 191)) {
    EXIT_CODE = 1;
  }
  if (shift) {
    for (int i = 191; i >= 0; i--) {
      bit = get_bite_from_big_decimal(*dcml, i);
      if (bit) {
        change_big_decimal_bit(dcml, bit, i + shift);
        change_big_decimal_bit(dcml, 0, i);
      }
    }
  }
  return EXIT_CODE;
}

int mod_big_decimal_by_ten(big_decimal dec, big_decimal *result) {
  int bit = 0;
  big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}};
  set_big_decimal_exp(&ten, get_big_decimal_exp(dec));
  change_big_decimal_bit(&dec, 0, 223);
  clear_big_decimal(result);

  int first_significant_bit = 191;
  for (; first_significant_bit >= 0; first_significant_bit--) {
    if (get_bite_from_big_decimal(dec, first_significant_bit)) {
      break;
    }
  }
  int sdvig = 0;

  while (bit == 0 && sdvig < 193) {
    sdvig++;
    DecimalShift_big_decimal(&ten, 1);
    bit = dec.bits[5] & (1 << 31);
    if (get_bite_from_big_decimal(ten, first_significant_bit)) {
      break;
    }
  }
  sdvig += 1;
  while (sdvig-- && sdvig != 192) {
    DecimalShift_big_decimal(result, 1);

    if (big_decimal_is_greater(ten, dec)) {
      change_big_decimal_bit(result, 0, 0);
    } else {
      big_decimal_sub(dec, ten, &dec);
      change_big_decimal_bit(result, 1, 0);
    }
    DecimalShiftRight_big_decimal(&ten, 1);
  }
  set_big_decimal_exp(result, get_big_decimal_exp(dec));

  return bit;
}
int check_three_first_ints_in_big_decimal(big_decimal dec) {
  int result = 0;
  for (int i = 96; i < 192; i++) {
    if (get_bite_from_big_decimal(dec, i)) {
      result = 1;
      break;
    }
  }

  return result;
}

int bank_round(big_decimal *dec) {
  int last_number = 0;
  int result_of_functions = 0;

  if (get_bite_from_big_decimal(*dec, 0)) {
    last_number += 1;
  }

  for (int i = 1; i < 192; i++) {
    if (get_bite_from_big_decimal(*dec, i)) {
      if (i % 4 == 0) {
        last_number += 6;
      } else if (i % 4 == 1) {
        last_number += 2;
      } else if (i % 4 == 2) {
        last_number += 4;
      } else {
        last_number += 8;
      }
    }
  }

  last_number %= 10;

  mod_big_decimal_by_ten(*dec, dec);

  if (last_number >= 5) {
    big_decimal buf = {{1, 0, 0, 0, 0, 0, 0}};
    set_big_decimal_exp(&buf, get_big_decimal_exp(*dec));

    change_big_decimal_bit(&buf, get_bite_from_big_decimal(*dec, 223), 223);
    result_of_functions = big_decimal_add(*dec, buf, dec);
  }

  if (last_number == 5) {
    // прибавить 1, если итоговое число будет заканчиваться на чётное число —
    // вычесть 1
    if (get_bite_from_big_decimal(*dec, 0)) {
      change_big_decimal_bit(dec, 0, 0);
    }
  }

  return result_of_functions;
}

int get_bite_from_decimal(s21_decimal dec, int position) {
  int return_value = 0;
  if (position < 32) {
    if (1 << position & dec.bits[0]) {
      return_value = 1;
    }
  } else if (position < 64) {
    if (1 << (position - 32) & dec.bits[1]) {
      return_value = 1;
    }
  } else if (position < 96) {
    if (1 << (position - 64) & dec.bits[2]) {
      return_value = 1;
    }
  } else if (position < 128) {
    if (1 << (position - 96) & dec.bits[3]) {
      return_value = 1;
    }
  }

  return return_value;
}

/**
 *Функция устанавливает значение определенного бита на то, какое нужно
 */

int set_bite_to_decimal(s21_decimal *decimal, int number, int bit) {
  int number_int = number / 32;
  int number_bit = number % 32;
  if (bit == 1) {
    decimal->bits[number_int] |= (1 << number_bit);
  } else {
    decimal->bits[number_int] &= (~((1) << number_bit));
  }
  return 0;
}

/**
 *Функция возвращает значение знака
 */

int get_sign_from_decimal(s21_decimal sign) {
  return get_bite_from_decimal(sign, 127);
}

/**
 *Функция устанавливает значение знака
 */

int set_sign_to_decimal(s21_decimal *decimal, int sign) {
  set_bite_to_decimal(decimal, 127, sign);
  return 0;
}

/**
 *Функция возвращает 1, если децимал равен 0
 */

int is_zero(s21_decimal value) {
  int is_zero = 0;

  if (!value.bits[0] && !value.bits[1] && !value.bits[2]) is_zero = 3;

  return is_zero;
}

/**
 *Функция обнуляет decimal (все биты decimal принимают значение 0)
 */

void clear_decimal(s21_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
}

/**
 *Функция возвращает значение exp данного decimal
 */

int get_decimal_exp(s21_decimal dec) {
  int exp = 0;

  for (int i = 16; i < 24; i++) {
    exp += pow(2, i - 16) * get_bite_from_decimal(dec, i + 96);
  }

  return exp;
}

/**
 *Функция меняет бит, находящийся на позиции position, на значение bit
 */
void change_decimal_bit(s21_decimal *dec, int bit, int position) {
  int bits = position / 32;
  position %= 32;

  if (bit) {
    dec->bits[bits] |= (1 << position);
  } else {
    dec->bits[bits] &= ~(1 << position);
  }
}

int set_decimal_exp(s21_decimal *dec, int exp) {
  int flag = 1;

  if (exp > 28 || exp < 0) {
    flag = 0;
  } else {
    for (int i = 20; i > 15; i--) {
      if (exp - pow(2, i - 16) >= 0) {
        change_decimal_bit(dec, 1, i + 96);
        exp -= pow(2, i - 16);
        // printf("%d\n", i);
      }
    }
  }

  return flag;
}

int GetExponent(s21_decimal dcml) {
  int bitmask = 0b11111111;
  bitmask = (bitmask << 16);
  bitmask &= dcml.bits[3];
  bitmask = bitmask >> 16;

  return bitmask;
}

int SetExponent(s21_decimal *dcml, int exp) {
  int EXIT_CODE = 0;
  if (exp > 28) {
    EXIT_CODE = 1;
  }
  if (!EXIT_CODE) {
    int bitmask = 0b11111111;
    bitmask = bitmask << 16;
    dcml->bits[3] &= ~bitmask;
    dcml->bits[3] |= exp << 16;
  }
  return EXIT_CODE;
}

// 262144

int DecimalShift(s21_decimal *dcml, int shift) {
  int EXIT_CODE = 0;
  int bit = 0;
  if (shift == 0) {
    EXIT_CODE = -1;
  } else {
    // check if there is space for shift
    for (int i = 95; i > 96 - shift; i--) {
      bit = get_bite_from_decimal(*dcml, i);
      if (bit) {
        EXIT_CODE = 1;
        break;
      }
    }

    if (!EXIT_CODE) {
      for (int i = 95; i >= 0; i--) {
        bit = get_bite_from_decimal(*dcml, i);
        if (bit) {
          SetBit(dcml, i + shift, bit);
          SetBit(dcml, i, 0);
        }
      }
    }
    // print_decimal(*dcml);
  }
  if (EXIT_CODE == -1) {
    EXIT_CODE = 0;
  }
  return EXIT_CODE;
}

int DecimalShiftRight(s21_decimal *dcml, int shift) {
  int EXIT_CODE = 0;
  int bit = 0;
  if (shift == 0) {
    EXIT_CODE = -1;
  } else {
    for (int i = 0; i < shift; i++) {
      bit = get_bite_from_decimal(*dcml, i);
      if (bit) {
        EXIT_CODE = 1;
        break;
      }
    }

    if (!EXIT_CODE) {
      for (int i = 0; i < 96; i++) {
        bit = get_bite_from_decimal(*dcml, i);
        if (bit) {
          SetBit(dcml, i - shift, bit);
          SetBit(dcml, i, 0);
        }
      }
    }
  }

  if (EXIT_CODE == -1) {
    EXIT_CODE = 0;
  }

  return EXIT_CODE;
}

// int print_decimal(s21_decimal value_1) {
//   int bit = 0;
//   for (int i = 127; i >= 0; i--) {
//     bit = get_bite_from_decimal(value_1, i);
//     printf("%d", bit);
//     if (i % 32 == 0) {
//       printf("|");
//     }
//   }
//   printf("\n");
//   return 1;
// }

/*
 *--------------------------------------------
 * ARIFMETIC OPERATIONS WITH BIG_DECIMAL     |
 *--------------------------------------------
 */

int big_decimal_sub(big_decimal value_1, big_decimal value_2,
                    big_decimal *result) {
  clear_big_decimal(result);
  int result_flag = 0;
  int add_value = 0;
  int buf_bit = 0;
  int bit1 = 0;
  int bit2 = 0;

  if (get_bite_from_big_decimal(value_1, 223) &&
      !get_bite_from_big_decimal(value_2, 223)) {
    change_big_decimal_bit(&value_2, 1, 223);
    result_flag = big_decimal_add(value_1, value_2, result);
  } else if (!get_bite_from_big_decimal(value_1, 223) &&
             get_bite_from_big_decimal(value_2, 223)) {
    change_big_decimal_bit(&value_2, 0, 223);
    result_flag = big_decimal_add(value_1, value_2, result);
  } else {
    equal_big_decimal_exp(&value_1, &value_2);

    for (int i = 0; i < 192; i++) {
      bit1 = get_bite_from_big_decimal(value_1, i);
      bit2 = get_bite_from_big_decimal(value_2, i);

      add_value = bit1 - bit2 - buf_bit;
      if (add_value < -1) {
        change_big_decimal_bit(result, 0, i);
      } else if (add_value == -1) {
        buf_bit = 1;
        change_big_decimal_bit(result, 1, i);
      } else {
        buf_bit = 0;
        change_big_decimal_bit(result, add_value, i);
      }
    }
    set_big_decimal_exp(result, get_big_decimal_exp(value_1));
    if (buf_bit == 1) {
      for (int i = 0; i < 192; i++) {
        if (get_bite_from_big_decimal(*result, i)) {
          change_big_decimal_bit(result, 0, i);
        } else {
          change_big_decimal_bit(result, 1, i);
        }
      }

      clear_big_decimal(&value_1);
      set_big_decimal_exp(&value_1, get_big_decimal_exp(*result));
      value_1.bits[0] = 1;
      result_flag = big_decimal_add(value_1, *result, result);
      change_big_decimal_bit(result, 1, 223);
    }
  }
  return result_flag;
}

int big_decimal_add(big_decimal value_1, big_decimal value_2,
                    big_decimal *result) {
  clear_big_decimal(result);

  int result_flag = 0;
  int buf_bit = 0;
  int add_value = 0;
  int bit1 = 0;
  int bit2 = 0;

  if (get_bite_from_big_decimal(value_1, 223) &&
      !get_bite_from_big_decimal(value_2, 223)) {
    change_big_decimal_bit(&value_1, 0, 223);
    result_flag = big_decimal_sub(value_2, value_1, result);
  } else if (!get_bite_from_big_decimal(value_1, 223) &&
             get_bite_from_big_decimal(value_2, 223)) {
    change_big_decimal_bit(&value_2, 0, 223);
    result_flag = big_decimal_sub(value_1, value_2, result);
  } else {
    equal_big_decimal_exp(&value_1, &value_2);
    equation_big_decimal(value_1, result);
    for (int j = 0; j < 192; j++) {
      bit1 = get_bite_from_big_decimal(value_2, j);
      bit2 = get_bite_from_big_decimal(value_1, j);

      add_value = (buf_bit + bit1 + bit2) % 2;
      buf_bit = (buf_bit + bit1 + bit2) / 2;

      change_big_decimal_bit(result, add_value, j);
    }
  }

  return result_flag;
}

/*
 *--------------------------------------------
 * ARIFMETIC OPERATIONS                      |
 *--------------------------------------------
 */

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int EXIT_CODE = 0;
  clear_decimal(result);
  big_decimal big_result = {{0, 0, 0, 0, 0, 0, 0}};
  big_decimal buf = {{0, 0, 0, 0, 0, 0, 0}};
  int exp_1 = GetExponent(value_1);
  int exp_2 = GetExponent(value_2);

  int sign_1 = get_bite_from_decimal(value_1, 127);
  int sign_2 = get_bite_from_decimal(value_2, 127);

  EXIT_CODE = s21_mul_mantissa(value_1, value_2, &big_result);
  set_big_decimal_exp(&big_result, exp_1 + exp_2);

  buf = big_result;

  int expp = get_big_decimal_exp(buf);
  while (expp) {
    bank_round(&buf);

    if (expp) {
      expp--;

      set_big_decimal_exp(&buf, expp);
    }
  }

  if (check_three_first_ints_in_big_decimal(buf) == 1) {
    if (get_bite_from_big_decimal(big_result, 223)) {
      EXIT_CODE = 2;
    } else {
      EXIT_CODE = 1;
    }
  }

  if (EXIT_CODE) {
    clear_big_decimal(&buf);
  }

  SetExponent(result, exp_1 + exp_2);
  *result = from_big_decimal_to_decimal(big_result);
  if (sign_1 ^ sign_2) {
    SetBit(result, 127, 1);
  }

  return EXIT_CODE;
}

int s21_mul_mantissa(s21_decimal value_1, s21_decimal value_2,
                     big_decimal *result) {
  int EXIT_CODE = 0;
  int bit = 0;

  SetBit(&value_1, 127, 0);
  SetBit(&value_2, 127, 0);
  SetExponent(&value_1, 0);
  SetExponent(&value_2, 0);
  clear_big_decimal(result);

  big_decimal value1 = from_decimal_to_big_decimal(value_1);
  big_decimal value2 = from_decimal_to_big_decimal(value_2);

  big_decimal tmp = {{0, 0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < 192; i++) {
    bit = get_bite_from_big_decimal(value2, i);
    if (bit) {
      tmp = value1;
      EXIT_CODE = DecimalShift_big_decimal(&tmp, i);
      if (!EXIT_CODE) {
        EXIT_CODE = big_decimal_add(*result, tmp, result);
      } else {
        break;
      }
    }
  }

  return EXIT_CODE;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // EITCODE: 0 - OK, 1 - NUMBER IS TOO LARGE
  //  2 - NUMBER IS TO SMALL, 3 - DIVISION BY 0

  int EXIT_CODE = 0;
  big_decimal value1 = from_decimal_to_big_decimal(value_1);
  big_decimal value2 = from_decimal_to_big_decimal(value_2);
  big_decimal res, buf = {{0, 0, 0, 0, 0, 0, 0}};
  clear_big_decimal(&res);

  big_decimal_add(value1, value2, &res);
  buf = res;
  while (get_big_decimal_exp(buf)) {
    bank_round(&buf);

    if (get_big_decimal_exp(buf)) {
      set_big_decimal_exp(&buf, get_big_decimal_exp(buf) - 1);
    }
  }

  if (check_three_first_ints_in_big_decimal(buf) == 1) {
    if (get_bite_from_big_decimal(res, 223)) {
      EXIT_CODE = 2;
    } else {
      EXIT_CODE = 1;
    }
  }
  if (EXIT_CODE) {
    clear_big_decimal(&buf);
  }
  *result = from_big_decimal_to_decimal(res);

  return EXIT_CODE;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int EXIT_CODE = 0;
  big_decimal value1 = from_decimal_to_big_decimal(value_1);
  big_decimal value2 = from_decimal_to_big_decimal(value_2);
  big_decimal res, buf = {{0, 0, 0, 0, 0, 0, 0}};
  clear_big_decimal(&res);

  big_decimal_sub(value1, value2, &res);
  buf = res;
  while (get_big_decimal_exp(buf)) {
    bank_round(&buf);
    if (get_big_decimal_exp(buf)) {
      set_big_decimal_exp(&buf, get_big_decimal_exp(buf) - 1);
    }
  }

  if (check_three_first_ints_in_big_decimal(buf) == 1) {
    if (get_bite_from_big_decimal(res, 223)) {
      EXIT_CODE = 2;
    } else {
      EXIT_CODE = 1;
    }
  }
  if (EXIT_CODE) {
    clear_big_decimal(&res);
  }
  *result = from_big_decimal_to_decimal(res);
  return EXIT_CODE;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;
  s21_decimal mul;
  mul.bits[0] = 0b00000000000000000000000000001010;
  mul.bits[1] = 0b00000000000000000000000000000000;
  mul.bits[2] = 0b00000000000000000000000000000000;
  mul.bits[3] = 0b00000000000000000000000000000000;
  clear_decimal(result);

  int exp_1 = GetExponent(value_1);
  int exp_2 = GetExponent(value_2);

  SetExponent(&val_1, 0);
  SetExponent(&val_2, 0);

  int bit = 0;
  int sign_1 = get_bite_from_decimal(value_1, 127);
  int sign_2 = get_bite_from_decimal(value_2, 127);

  int error = is_zero(value_2);

  if (sign_1 != sign_2 && !error) {
    set_sign_to_decimal(result, 1);
  } else {
    set_sign_to_decimal(result, 0);
  }

  set_sign_to_decimal(&val_1, 0);
  set_sign_to_decimal(&val_2, 0);

  int first_significant_bit = 95;
  for (; first_significant_bit >= 0; first_significant_bit--) {
    if (get_bite_from_decimal(val_1, first_significant_bit)) {
      break;
    }
  }
  int i = 0, sdvig = 0;

  while ((bit == 0) && !(error)) {
    sdvig++;
    DecimalShift(&val_2, 1);
    bit = val_2.bits[2] & (1 << 31);
    if (get_bite_from_decimal(val_2, first_significant_bit)) {
      break;
    }
  }
  sdvig += 1;

  while (sdvig-- && !(error)) {
    DecimalShift(result, 1);

    if (s21_is_greater(val_2, val_1)) {
      set_bite_to_decimal(result, 0, 0);

    } else {
      s21_sub(val_1, val_2, &val_1);
      set_bite_to_decimal(result, 0, 1);

      i++;
    }
    DecimalShiftRight(&val_2, 1);
  }

  if (exp_1 > exp_2 && !error) {
    SetExponent(result, exp_1 - exp_2);
  } else if (exp_1 < exp_2 && !error) {
    for (int i = 0; i < (exp_2 - exp_1); i++) {
      s21_mul(*result, mul, result);
      set_decimal_exp(&mul, get_decimal_exp(*result));
    }
  }

  return error;
}

//------------------------------------------------------------------
// Сравнения decimal'ов
//------------------------------------------------------------------

/**
 *Функция получает на вход 2 decimal  и проверяет,
 *является ли левый меньше, чем правый. В случае
 *верности утверждения возвращает 1, в противном
 *случае 0
 */

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int return_value = 0;

  big_decimal value1 = from_decimal_to_big_decimal(value_1);
  big_decimal value2 = from_decimal_to_big_decimal(value_2);

  int sign_1 = get_bite_from_big_decimal(value1, 223);
  int sign_2 = get_bite_from_big_decimal(value2, 223);

  if (check_for_one(value1) || check_for_one(value2)) {
    if (sign_1 ^ sign_2) {
      return_value = (sign_1 > sign_2) ? 1 : 0;
    } else {
      equal_big_decimal_exp(&value1, &value2);
      for (int i = 191; i >= 0; i--) {
        int bite_1 = get_bite_from_big_decimal(value1, i);
        int bite_2 = get_bite_from_big_decimal(value2, i);

        if (bite_1 > bite_2) {
          return_value = (sign_1) ? 1 : 0;
          break;
        } else if (bite_1 < bite_2) {
          return_value = (sign_1) ? 0 : 1;

          break;
        }
      }
    }
  }

  return return_value;
}

/**
 *Функция получает на вход 2 decimal  и проверяет,
 *является ли левый больше, чем правый. В случае
 *верности утверждения возвращает 1, в противном
 *случае 0
 */

int big_decimal_is_greater(big_decimal value1, big_decimal value2) {
  int return_value = 0;

  int sign_1 = get_bite_from_big_decimal(value1, 223);
  int sign_2 = get_bite_from_big_decimal(value2, 223);

  if (check_for_one(value1) || check_for_one(value2)) {
    if (sign_1 ^ sign_2) {
      return_value = (sign_1 < sign_2) ? 1 : 0;
    } else {
      equal_big_decimal_exp(&value1, &value2);
      for (int i = 191; i >= 0; i--) {
        int bite_1 = get_bite_from_big_decimal(value1, i);
        int bite_2 = get_bite_from_big_decimal(value2, i);

        if (bite_1 > bite_2) {
          return_value = (sign_1) ? 0 : 1;
          break;
        } else if (bite_1 < bite_2) {
          return_value = (sign_1) ? 1 : 0;
          break;
        }
      }
    }
  }

  return return_value;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  big_decimal value1 = from_decimal_to_big_decimal(value_1);
  big_decimal value2 = from_decimal_to_big_decimal(value_2);
  int result = big_decimal_is_greater(value1, value2);

  return result;
}

/**
 *Функция получает на вход 2 decimal  и проверяет,
 *является ли левый меньше, чем правый, или равен
 *ему. В случае верности утверждения возвращает 1,
 *в противном случае 0
 */

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {  // (<=)
  int return_value = 1;

  big_decimal value1 = from_decimal_to_big_decimal(value_1);
  big_decimal value2 = from_decimal_to_big_decimal(value_2);

  int sign_1 = get_bite_from_big_decimal(value1, 223);
  int sign_2 = get_bite_from_big_decimal(value2, 223);

  if (check_for_one(value1) || check_for_one(value2)) {
    if (sign_1 ^ sign_2) {
      return_value = (sign_1 > sign_2) ? 1 : 0;
    } else {
      equal_big_decimal_exp(&value1, &value2);
      for (int i = 191; i >= 0; i--) {
        int bite_1 = get_bite_from_big_decimal(value1, i);
        int bite_2 = get_bite_from_big_decimal(value2, i);

        if (bite_1 > bite_2) {
          return_value = (sign_1) ? 1 : 0;
          break;
        } else if (bite_1 < bite_2) {
          return_value = (sign_1) ? 0 : 1;
          break;
        }
      }
    }
  }

  return return_value;
}

/**
 *Функция получает на вход 2 decimal  и проверяет,
 *является ли левый больше, чем правый, или равен
 *ему. В случае верности утверждения возвращает 1,
 *в противном случае 0
 */

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int return_value = 1;

  big_decimal value1 = from_decimal_to_big_decimal(value_1);
  big_decimal value2 = from_decimal_to_big_decimal(value_2);

  int sign_1 = get_bite_from_big_decimal(value1, 223);
  int sign_2 = get_bite_from_big_decimal(value2, 223);

  if (check_for_one(value1) || check_for_one(value2)) {
    if (sign_1 ^ sign_2) {
      return_value = (sign_1 < sign_2) ? 1 : 0;
    } else {
      equal_big_decimal_exp(&value1, &value2);
      for (int i = 191; i >= 0; i--) {
        int bite_1 = get_bite_from_big_decimal(value1, i);
        int bite_2 = get_bite_from_big_decimal(value2, i);

        if (bite_1 > bite_2) {
          return_value = (sign_1) ? 0 : 1;
          break;
        } else if (bite_1 < bite_2) {
          return_value = (sign_1) ? 1 : 0;
          break;
        }
      }
    }
  }

  return return_value;
}

/**
 *Функция получает на вход 2 decimal  и проверяет,
 *равны ли эти числа. В случае верности утверждения
 *возвращает 1, в противном случае 0
 */

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int return_value = 1;

  big_decimal value1 = from_decimal_to_big_decimal(value_1);
  big_decimal value2 = from_decimal_to_big_decimal(value_2);

  int sign_1 = get_bite_from_big_decimal(value1, 223);
  int sign_2 = get_bite_from_big_decimal(value2, 223);

  if (check_for_one(value1) || check_for_one(value2)) {
    if (sign_1 ^ sign_2) {
      return_value = 0;
    } else {
      equal_big_decimal_exp(&value1, &value2);

      for (int i = 191; i >= 0; i--) {
        int bite_1 = get_bite_from_big_decimal(value1, i);
        int bite_2 = get_bite_from_big_decimal(value2, i);

        if (bite_1 ^ bite_2) {
          return_value = 0;
          break;
        }
      }
    }
  }

  return return_value;
}

/**
 *Функция получает на вход 2 decimal  и проверяет,
 *неравенства чисел друг другу. В случае верности
 *утверждения возвращает 1, в противном случае 0
 */

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_is_equal(value_1, value_2)) ? 0 : 1;
}

//------------------------------------------------------------------
// Функции перевода
//------------------------------------------------------------------

big_decimal from_decimal_to_big_decimal(s21_decimal dec) {
  big_decimal result = {{0, 0, 0, 0, 0, 0, 0}};

  result.bits[0] = dec.bits[0];
  result.bits[1] = dec.bits[1];
  result.bits[2] = dec.bits[2];

  result.bits[6] = dec.bits[3];

  return result;
}

s21_decimal from_big_decimal_to_decimal(big_decimal dec) {
  s21_decimal result = {{0}};
  int exp = get_big_decimal_exp(dec);
  while (check_three_first_ints_in_big_decimal(dec)) {
    bank_round(&dec);
    if (exp) {
      exp--;
      set_big_decimal_exp(&dec, exp);
    }
  }

  result.bits[0] = dec.bits[0];
  result.bits[1] = dec.bits[1];
  result.bits[2] = dec.bits[2];
  result.bits[3] = dec.bits[6];
  return result;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  clear_decimal(dst);
  if (src < 0) {
    src = src - 1;
    dst->bits[3] |= (1 << 31);
    for (int i = 0; i < 32; i++) {
      if (1 << i & src) {
        dst->bits[0] &= ~(1 << i);
      } else {
        dst->bits[0] |= (1 << i);
      }
    }
  } else {
    dst->bits[0] = src;
  }

  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int code_error = 0;
  s21_truncate(src, &src);
  int sing = get_bite_from_decimal(src, 127);
  if (src.bits[2] || src.bits[1] || src.bits[0] > INT_MAX) {
    code_error = 1;
  } else {
    *dst = src.bits[0];
    if (sing) {
      *dst *= -1;
    }
  }
  if (*dst < 0 && !sing) {
    code_error = 1;
  }
  return code_error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int EXIT_CODE = 0;
  clear_decimal(dst);
  int prec = 8;
  int exp = 0;
  int j = 0;
  char stroka[16] = " ";
  char str[16] = " ";
  while ((int)strlen(stroka) != (8 + (src < 0))) {
    prec--;
    memset(stroka, 0, strlen(stroka));
    sprintf(stroka, "%.*f", prec, src);
    if (strcmp(stroka, "inf") == 0 || strcmp(stroka, "-inf") == 0 ||
        strcmp(stroka, "nan") == 0) {
      EXIT_CODE = 1;
      break;
    }
  }
  // printf("\n%s\n", stroka);
  if (!EXIT_CODE) {
    for (int i = (int)strlen(stroka) - 1; i >= 0; i--) {
      if (stroka[i] == '0') {
        stroka[i] = '\0';
      } else
        break;
    }

    for (int i = 0; i < (int)strlen(stroka); i++) {
      if (stroka[i] != '.') {
        str[j] = stroka[i];
        j++;
      }
    }

    // printf("new str \n%s\n", str);

    for (int i = (int)strlen(stroka); i >= 0; i--) {
      if (stroka[i] != '.') {
        exp++;
      } else {
        break;
      }
    }
    exp -= 1;
    // printf("exp: %d\n", exp);
    int k = atoi(str);
    // printf("%d\n", k);

    s21_from_int_to_decimal(k, dst);

    set_decimal_exp(dst, exp);
  }
  // print_decimal(*dst);

  return EXIT_CODE;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int code_error = 0;
  int sign = get_bite_from_decimal(src, 127);
  *dst = (src.bits[2] * pow(2, 64) + src.bits[1] * pow(2, 32) + src.bits[0]) /
         pow(10, get_decimal_exp(src));
  if (sign) {
    *dst *= -1;
  }
  if ((fabs(*dst) < 1e-28) && (fabs(*dst) > 0)) {
    code_error = 1;
  }
  return code_error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int return_value = 0;
  int k = GetExponent(value);
  if (result) {
    for (int i = 0; i < k; i++) {
      s21_decimal buf = {{10, 0, 0, 0}};

      set_decimal_exp(&buf, get_decimal_exp(value));

      s21_div(value, buf, &value);
    }
  } else {
    return_value = 1;
  }
  set_decimal_exp(&value, 0);
  *result = value;

  return return_value;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int return_flag = 0;
  int last_digit = 0;
  int iterations = get_decimal_exp(value);
  SetExponent(&value, 0);

  s21_decimal buf = {{0, 0, 0, 0}};

  for (int i = 0; i < iterations; i++) {
    last_digit = 0;
    if (get_bite_from_decimal(value, 0)) {
      last_digit += 1;
    }

    for (int i = 1; i < 96; i++) {
      if (get_bite_from_decimal(value, i)) {
        if (i % 4 == 1) {
          last_digit += 2;
        } else if (i % 4 == 2) {
          last_digit += 4;
        } else if (i % 4 == 3) {
          last_digit += 8;
        } else if (i % 4 == 0) {
          last_digit += 6;
        }
      }
    }
    last_digit %= 10;
    buf.bits[0] = 10;
    return_flag = s21_div(value, buf, &value);
  }

  if (last_digit > 4) {
    set_bite_to_decimal(&buf, 127, get_bite_from_decimal(value, 127));
    buf.bits[0] = 1;
    return_flag = s21_add(value, buf, &value);
  }
  *result = value;
  return return_flag;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int sign = get_sign_from_decimal(value);
  int exp = GetExponent(value);
  s21_decimal one;

  one.bits[0] = 0b00000000000000000000000000000001;
  one.bits[1] = 0b00000000000000000000000000000000;
  one.bits[2] = 0b00000000000000000000000000000000;
  one.bits[3] = 0b00000000000000000000000000000000;

  if (sign && exp) {
    s21_truncate(value, result);

    s21_sub(*result, one, result);

  } else {
    s21_truncate(value, result);
  }

  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  for (int i = 0; i < 4; i++) {
    result->bits[i] = value.bits[i];
  }
  if (get_sign_from_decimal(value)) {
    set_sign_to_decimal(result, 0);
  } else {
    set_sign_to_decimal(result, 1);
  }

  return 0;
}
