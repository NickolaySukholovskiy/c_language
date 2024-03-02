
#include <check.h>
#include <stdio.h>
#include <string.h>

#include "backend/s21_calc.h"

START_TEST(polish_notation_all_1) {
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1+1\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;

  char str_result[] = "1,1,+\0";

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  ck_assert_str_eq(str_postfix, str_result);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_all_2) {
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1*1\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;

  char str_result[] = "1,1,*\0";

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  ck_assert_str_eq(str_postfix, str_result);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_all_3) {
  char *ptr_str = calloc(8, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1*(1+1)\0");

  char *ptr_postfix = calloc(9, sizeof(char));
  char *str_postfix = ptr_postfix;

  char str_result[] = "1,1,1,+*\0";

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  ck_assert_str_eq(str_postfix, str_result);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_all_4) {
  char *ptr_str = calloc(9, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "sin(1+2)\0");

  char *ptr_postfix = calloc(7, sizeof(char));
  char *str_postfix = ptr_postfix;

  char str_result[] = "1,2,+s\0";

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  ck_assert_str_eq(str_postfix, str_result);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_all_5) {
  char *ptr_str = calloc(8, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "(1+2)^3\0");

  char *ptr_postfix = calloc(10, sizeof(char));
  char *str_postfix = ptr_postfix;

  char str_result[] = "1,2,+3,^\0";

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  ck_assert_str_eq(str_postfix, str_result);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_all_6) {
  char *ptr_str = calloc(12, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "2*2+3-3*2^2\0");

  char *ptr_postfix = calloc(18, sizeof(char));
  char *str_postfix = ptr_postfix;

  char str_result[] = "2,2,*3,+3,2,2,^*-\0";

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  ck_assert_str_eq(str_postfix, str_result);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_all_7) {
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "2+x\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;

  char str_result[] = "2,x,+\0";

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  ck_assert_str_eq(str_postfix, str_result);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_all_8) {
  char *ptr_str = calloc(3, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "-1\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;

  char str_result[] = "1,~\0";

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  ck_assert_str_eq(str_postfix, str_result);

  free(str_str);
  free(str_postfix);
}
END_TEST

Suite *suite_polish_all(void) {
  Suite *s;
  TCase *tc_core = tcase_create("polish_notation");

  s = suite_create("polish_notation_all");
  tcase_add_test(tc_core, polish_notation_all_1);
  tcase_add_test(tc_core, polish_notation_all_2);
  tcase_add_test(tc_core, polish_notation_all_3);
  tcase_add_test(tc_core, polish_notation_all_4);
  tcase_add_test(tc_core, polish_notation_all_5);
  tcase_add_test(tc_core, polish_notation_all_6);
  tcase_add_test(tc_core, polish_notation_all_7);
  tcase_add_test(tc_core, polish_notation_all_8);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(polish_notation_error_1) {
  char *ptr_str = calloc(5, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "(1+2\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_error_2) {
  char *ptr_str = calloc(5, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1+2)\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_error_3) {
  char *ptr_str = calloc(7, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "((1+2)\0");

  char *ptr_postfix = calloc(10, sizeof(char));
  char *str_postfix = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_error_4) {
  char *ptr_str = calloc(7, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1.1.43\0");

  char *ptr_postfix = calloc(7, sizeof(char));
  char *str_postfix = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_error_5) {
  char *ptr_str = calloc(3, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, ".1\0");

  char *ptr_postfix = calloc(3, sizeof(char));
  char *str_postfix = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_error_6) {
  char *ptr_str = calloc(3, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1.\0");

  char *ptr_postfix = calloc(3, sizeof(char));
  char *str_postfix = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_error_7) {
  char *ptr_str = calloc(3, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "x.\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix);
}
END_TEST

START_TEST(polish_notation_error_8) {
  char *ptr_str = calloc(3, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, ".x\0");

  char *ptr_postfix = calloc(3, sizeof(char));
  char *str_postfix = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix);
}
END_TEST

Suite *suite_polish_error(void) {
  Suite *s;
  TCase *tc_core = tcase_create("polish_notation_error");

  s = suite_create("polish_notation_error");
  tcase_add_test(tc_core, polish_notation_error_1);
  tcase_add_test(tc_core, polish_notation_error_2);
  tcase_add_test(tc_core, polish_notation_error_3);
  tcase_add_test(tc_core, polish_notation_error_4);
  tcase_add_test(tc_core, polish_notation_error_5);
  tcase_add_test(tc_core, polish_notation_error_6);
  tcase_add_test(tc_core, polish_notation_error_7);
  tcase_add_test(tc_core, polish_notation_error_8);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(check_result_1) {
  double double_result = 0;
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "2+2\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 4);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_2) {
  double double_result = 0;
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "2*7\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 14);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_3) {
  double double_result = 0;
  char *ptr_str = calloc(10, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "(2+2)*3-7\0");

  char *ptr_postfix = calloc(20, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 5);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_4) {
  double double_result = 0;
  char *ptr_str = calloc(9, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "sin(1.5)\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, sin(1.5));

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_5) {
  double double_result = 0;
  char *ptr_str = calloc(12, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "(1.5+0.5)^2\0");

  char *ptr_postfix = calloc(20, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 4);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_6) {
  double double_result = 0;
  char *ptr_str = calloc(6, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "-1.75\0");

  char *ptr_postfix = calloc(7, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, -1.75);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_7) {
  double double_result = 0;
  char *ptr_str = calloc(7, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1.75%1\0");

  char *ptr_postfix = calloc(10, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 0.75);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_8) {
  double double_result = 0;
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1+x\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 8);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_9) {
  double double_result = 0;
  char *ptr_str = calloc(8, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "sqrt(4)\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 2);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_10) {
  double double_result = 0;
  char *ptr_str = calloc(7, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "cos(0)\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 1);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_11) {
  double double_result = 0;
  char *ptr_str = calloc(7, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "tan(0)\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, tan(0));

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_12) {
  double double_result = 0;
  char *ptr_str = calloc(8, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "asin(0)\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, asin(0));

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_13) {
  double double_result = 0;
  char *ptr_str = calloc(8, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "acos(0)\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, acos(0));

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_14) {
  double double_result = 0;
  char *ptr_str = calloc(8, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "atan(0)\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, atan(0));

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_15) {
  double double_result = 0;
  char *ptr_str = calloc(7, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "log(0)\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_16) {
  double double_result = 0;
  char *ptr_str = calloc(6, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "ln(5)\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, log(5));

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_17) {
  double double_result = 0;
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "4/2\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  ck_assert_int_eq(result, SUCCESS);

  result = from_postfix_to_result(&str_postfix, &double_result, 7);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_double_eq(double_result, 4 / 2);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

Suite *suite_result_test(void) {
  Suite *s;
  TCase *tc_core = tcase_create("check_result");

  s = suite_create("check_result");
  tcase_add_test(tc_core, check_result_1);
  tcase_add_test(tc_core, check_result_2);
  tcase_add_test(tc_core, check_result_3);
  tcase_add_test(tc_core, check_result_4);
  tcase_add_test(tc_core, check_result_5);
  tcase_add_test(tc_core, check_result_6);
  tcase_add_test(tc_core, check_result_7);
  tcase_add_test(tc_core, check_result_8);
  tcase_add_test(tc_core, check_result_9);
  tcase_add_test(tc_core, check_result_10);
  tcase_add_test(tc_core, check_result_11);
  tcase_add_test(tc_core, check_result_12);
  tcase_add_test(tc_core, check_result_13);
  tcase_add_test(tc_core, check_result_14);
  tcase_add_test(tc_core, check_result_15);
  tcase_add_test(tc_core, check_result_16);
  tcase_add_test(tc_core, check_result_17);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(check_result_error_1) {
  double double_result = 0;
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "(-)\0");

  char *ptr_postfix = calloc(2, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_error_2) {
  double double_result = 0;
  char *ptr_str = calloc(3, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "2-\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_error_3) {
  double double_result = 0;
  char *ptr_str = calloc(3, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, ")(\0");

  char *ptr_postfix = calloc(3, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);
  if (result == SUCCESS) {
    result = from_postfix_to_result(&str_postfix, &double_result, 0);
    ck_assert_int_eq(result, FAILURE);
  }

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_error_4) {
  double double_result = 0;
  char *ptr_str = calloc(3, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "+2\0");

  char *ptr_postfix = calloc(4, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_error_5) {
  double double_result = 0;
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "1/0\0");

  char *ptr_postfix = calloc(6, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

START_TEST(check_result_error_6) {
  double double_result = 0;
  char *ptr_str = calloc(6, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "2.7%0\0");

  char *ptr_postfix = calloc(8, sizeof(char));
  char *str_postfix = ptr_postfix;
  char *str_postfix_to_free = ptr_postfix;

  int result = string_parser_to_postfix(&ptr_str, &ptr_postfix);

  result = from_postfix_to_result(&str_postfix, &double_result, 0);
  ck_assert_int_eq(result, FAILURE);

  free(str_str);
  free(str_postfix_to_free);
}
END_TEST

Suite *suite_result_test_error(void) {
  Suite *s;
  TCase *tc_core = tcase_create("check_result_error");

  s = suite_create("check_result_error");
  tcase_add_test(tc_core, check_result_error_1);
  tcase_add_test(tc_core, check_result_error_2);
  tcase_add_test(tc_core, check_result_error_3);
  tcase_add_test(tc_core, check_result_error_4);
  tcase_add_test(tc_core, check_result_error_5);
  tcase_add_test(tc_core, check_result_error_6);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(check_other_1) {
  char *ptr_str = calloc(4, sizeof(char));
  char *str_str = ptr_str;
  strcpy(ptr_str, "4/2\0");
  double result = 0;

  s21_connect_number(ptr_str, &result);
  ck_assert_double_eq(result, 2);

  free(str_str);
}
END_TEST

START_TEST(check_other_2) {
  double ammount = 100, percent = 20, result = 0;
  int months = 12;

  annuitent_function(ammount, percent, months, &result);

  ck_assert_double_eq_tol(result, 9.26, 0.01);
}
END_TEST

START_TEST(check_other_3) {
  double ammount = 100, percent = 20, result_1 = 0, result_2 = 0,
         result_percent = 0;
  int months = 12;

  differential_function(ammount, percent, months, &result_1, &result_2,
                        &result_percent);

  ck_assert_double_eq_tol(result_1, 10, 1);
  ck_assert_double_eq_tol(result_2, 8.47, 0.01);
  ck_assert_double_eq_tol(result_percent, 11, 1);
}
END_TEST

START_TEST(check_other_4) {
  double ammount = 100, percent = 20, result = 0;
  int months = 12;

  contribution_function(ammount, percent, months, &result);

  ck_assert_double_eq(result, 120);
}
END_TEST

Suite *suite_test_other(void) {
  Suite *s;
  TCase *tc_core = tcase_create("check_other");

  s = suite_create("check_other");
  tcase_add_test(tc_core, check_other_1);
  tcase_add_test(tc_core, check_other_2);
  tcase_add_test(tc_core, check_other_3);
  tcase_add_test(tc_core, check_other_4);
  suite_add_tcase(s, tc_core);

  return s;
}

int number_test_failed(void) {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;

  s = suite_polish_all();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = suite_polish_error();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = suite_result_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = suite_result_test_error();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = suite_test_other();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  return number_failed;
}

int main() {
  int number_failed = number_test_failed();
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
