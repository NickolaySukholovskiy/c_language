
#include <check.h>

#include "s21_matrix.h"

START_TEST(test_create_matrix_1) {
  matrix_t origin;

  int result = s21_create_matrix(-1, 2, &origin);
  ck_assert_int_eq(result, 1);
}

START_TEST(test_create_matrix_2) {
  matrix_t origin;

  int result = s21_create_matrix(-1, -2, &origin);
  ck_assert_int_eq(result, 1);
}

START_TEST(test_create_matrix_3) {
  matrix_t origin;

  int result = s21_create_matrix(1, 2, &origin);

  for (int i = 0; i < 2; i++) {
    origin.matrix[0][i] = 5.5;
  }

  ck_assert_double_eq(origin.matrix[0][0], 5.5);
  ck_assert_double_eq(origin.matrix[0][1], 5.5);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&origin);
}

START_TEST(test_create_matrix_4) {
  int result = s21_create_matrix(1, 2, NULL);

  ck_assert_int_eq(result, 1);
}

START_TEST(test_remove_matrix_1) {
  matrix_t origin;
  int result = s21_create_matrix(1, 2, &origin);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&origin);
  ck_assert_ptr_null(origin.matrix);
}

Suite *create_matrix_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("create_matrix");
  tcase_add_test(tc_core, test_create_matrix_1);
  tcase_add_test(tc_core, test_create_matrix_2);
  tcase_add_test(tc_core, test_create_matrix_3);
  tcase_add_test(tc_core, test_create_matrix_4);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *remove_matrix_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("remove_matrix");
  tcase_add_test(tc_core, test_remove_matrix_1);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_eq_matrix_1) {
  matrix_t origin_1, origin_2;
  int result = s21_create_matrix(1, 2, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(1, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  for (int i = 0; i < 2; i++) {
    origin_1.matrix[0][i] = 10;
    origin_2.matrix[0][i] = 10;
  }

  result = s21_eq_matrix(&origin_1, &origin_2);
  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
  ck_assert_int_eq(result, 1);
}

START_TEST(test_eq_matrix_2) {
  matrix_t origin;
  int result = s21_create_matrix(1, 2, &origin);
  ck_assert_int_eq(result, 0);

  for (int i = 0; i < 2; i++) {
    origin.matrix[0][i] = 10;
  }

  result = s21_eq_matrix(NULL, &origin);
  s21_remove_matrix(&origin);
  ck_assert_int_eq(result, 0);
}

START_TEST(test_eq_matrix_3) {
  int result = s21_eq_matrix(NULL, NULL);
  ck_assert_int_eq(result, 0);
}

START_TEST(test_eq_matrix_4) {
  matrix_t origin;
  int result = s21_create_matrix(2, 2, &origin);
  ck_assert_int_eq(result, 0);

  origin.matrix[0][0] = 1;
  origin.matrix[0][1] = 2;
  origin.matrix[1][0] = 3;
  origin.matrix[1][1] = 4;

  result = s21_eq_matrix(&origin, &origin);
  s21_remove_matrix(&origin);
  ck_assert_int_eq(result, 1);
}

START_TEST(test_eq_matrix_5) {
  matrix_t origin_1, origin_2;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  result = s21_create_matrix(2, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 4;

  origin_2.matrix[0][0] = 1;
  origin_2.matrix[0][1] = 3;
  origin_2.matrix[1][0] = 3;
  origin_2.matrix[1][1] = 4;

  result = s21_eq_matrix(&origin_1, &origin_2);
  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
  ck_assert_int_eq(result, 0);
}

Suite *eq_matrix_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("eq_matrix");
  tcase_add_test(tc_core, test_eq_matrix_1);
  tcase_add_test(tc_core, test_eq_matrix_2);
  tcase_add_test(tc_core, test_eq_matrix_3);
  tcase_add_test(tc_core, test_eq_matrix_4);
  tcase_add_test(tc_core, test_eq_matrix_5);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sum_matrix_1) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(2, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = -3.5;

  origin_2.matrix[0][0] = 2;
  origin_2.matrix[0][1] = 2.4;
  origin_2.matrix[1][0] = 32.3;
  origin_2.matrix[1][1] = 0;

  result = s21_sum_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_double_eq(result_matrix.matrix[0][0], 3);
  ck_assert_double_eq(result_matrix.matrix[0][1], 4.4);
  ck_assert_double_eq(result_matrix.matrix[1][0], 35.3);
  ck_assert_double_eq(result_matrix.matrix[1][1], -3.5);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_sum_matrix_2) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  result = s21_sum_matrix(&origin_1, NULL, &result_matrix);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&origin_1);
}

START_TEST(test_sum_matrix_3) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_2.matrix = NULL;

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  result = s21_sum_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
}

START_TEST(test_sum_matrix_4) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(2, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_2.rows = -1;

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  result = s21_sum_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 1);

  origin_2.rows = 2;
  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
}

START_TEST(test_sum_matrix_5) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(3, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  result = s21_sum_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
}

Suite *sum_matrix_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("sum_matrix");
  tcase_add_test(tc_core, test_sum_matrix_1);
  tcase_add_test(tc_core, test_sum_matrix_2);
  tcase_add_test(tc_core, test_sum_matrix_3);
  tcase_add_test(tc_core, test_sum_matrix_4);
  tcase_add_test(tc_core, test_sum_matrix_5);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sub_matrix_1) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(2, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1.1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  origin_2.matrix[0][0] = 2;
  origin_2.matrix[0][1] = 2.4;
  origin_2.matrix[1][0] = 32;
  origin_2.matrix[1][1] = 0;

  result = s21_sub_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_float_eq((float)result_matrix.matrix[0][0], -0.9);
  ck_assert_float_eq((float)result_matrix.matrix[0][1], -0.4);
  ck_assert_double_eq(result_matrix.matrix[1][0], -29);
  ck_assert_double_eq(result_matrix.matrix[1][1], 3);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_sub_matrix_2) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  result = s21_sub_matrix(&origin_1, NULL, &result_matrix);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&origin_1);
}

START_TEST(test_sub_matrix_3) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_2.matrix = NULL;

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  result = s21_sub_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&origin_1);
}

START_TEST(test_sub_matrix_4) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(2, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_2.rows = -1;

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  result = s21_sub_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&origin_1);

  origin_2.rows = 2;
  s21_remove_matrix(&origin_2);
}

START_TEST(test_sub_matrix_5) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(3, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 3;

  result = s21_sub_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
}

START_TEST(test_sub_matrix_6) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(1, 2, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(1, 2, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1.1;
  origin_1.matrix[0][1] = 2;

  origin_2.matrix[0][0] = 2;
  origin_2.matrix[0][1] = 2.4;

  result = s21_sub_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_float_eq((float)result_matrix.matrix[0][0], -0.9);
  ck_assert_float_eq((float)result_matrix.matrix[0][1], -0.4);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
  s21_remove_matrix(&result_matrix);
}

Suite *sub_matrix_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("sub_matrix");
  tcase_add_test(tc_core, test_sub_matrix_1);
  tcase_add_test(tc_core, test_sub_matrix_2);
  tcase_add_test(tc_core, test_sub_matrix_3);
  tcase_add_test(tc_core, test_sub_matrix_4);
  tcase_add_test(tc_core, test_sub_matrix_5);
  tcase_add_test(tc_core, test_sub_matrix_6);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_mult_matrix_1) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 3, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(3, 1, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 7;
  origin_1.matrix[1][2] = 0.1;

  origin_2.matrix[0][0] = 1;
  origin_2.matrix[1][0] = 32;
  origin_2.matrix[2][0] = 3;

  result = s21_mult_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_double_eq(result_matrix.matrix[0][0], 71);
  ck_assert_double_eq(result_matrix.matrix[1][0], 227.3);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_mult_matrix_2) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 3, &origin_1);
  ck_assert_int_eq(result, 0);
  result = s21_create_matrix(4, 1, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 7;
  origin_1.matrix[1][2] = 0.1;

  result = s21_mult_matrix(&origin_1, &origin_2, &result_matrix);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&origin_2);
}

START_TEST(test_mult_matrix_3) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(2, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 7;
  origin_1.matrix[1][2] = 0.1;

  result = s21_mult_matrix(&origin_1, NULL, &result_matrix);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&origin_1);
}

START_TEST(test_mult_matrix_4) {
  matrix_t origin_1, origin_2, result_matrix;
  int result = s21_create_matrix(2, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  result = s21_create_matrix(3, 3, &origin_2);
  ck_assert_int_eq(result, 0);

  origin_2.rows = -3;

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 7;
  origin_1.matrix[1][2] = 0.1;

  result = s21_mult_matrix(&origin_1, NULL, &result_matrix);
  ck_assert_int_eq(result, 1);

  s21_remove_matrix(&origin_1);
  origin_2.rows = 3;
  s21_remove_matrix(&origin_2);
}

Suite *mult_matrix_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("mult_matrix");
  tcase_add_test(tc_core, test_mult_matrix_1);
  tcase_add_test(tc_core, test_mult_matrix_2);
  tcase_add_test(tc_core, test_mult_matrix_3);
  tcase_add_test(tc_core, test_mult_matrix_4);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_mult_number_1) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(2, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 7;
  origin_1.matrix[1][2] = 0.1;

  result = s21_mult_number(&origin_1, 2, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_double_eq(result_matrix.matrix[0][0], 2);
  ck_assert_double_eq(result_matrix.matrix[0][1], 4);
  ck_assert_double_eq(result_matrix.matrix[0][2], 4);
  ck_assert_double_eq(result_matrix.matrix[1][0], 6);
  ck_assert_double_eq(result_matrix.matrix[1][1], 14);
  ck_assert_double_eq(result_matrix.matrix[1][2], 0.2);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_mult_number_2) {
  matrix_t result_matrix;

  int result = s21_mult_number(NULL, 2, &result_matrix);
  ck_assert_int_eq(result, 1);
}

START_TEST(test_mult_number_3) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(2, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix = NULL;

  result = s21_mult_number(&origin_1, 2, &result_matrix);
  ck_assert_int_eq(result, 1);
}

Suite *mult_number_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("mult_matrix");
  tcase_add_test(tc_core, test_mult_number_1);
  tcase_add_test(tc_core, test_mult_number_2);
  tcase_add_test(tc_core, test_mult_number_3);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_transpose_1) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(2, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 3;
  origin_1.matrix[1][0] = 4;
  origin_1.matrix[1][1] = 5;
  origin_1.matrix[1][2] = 6;

  result = s21_transpose(&origin_1, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_double_eq(result_matrix.matrix[0][0], 1);
  ck_assert_double_eq(result_matrix.matrix[1][0], 2);
  ck_assert_double_eq(result_matrix.matrix[2][0], 3);
  ck_assert_double_eq(result_matrix.matrix[0][1], 4);
  ck_assert_double_eq(result_matrix.matrix[1][1], 5);
  ck_assert_double_eq(result_matrix.matrix[2][1], 6);
}

Suite *transpose_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("transpose_matrix");
  tcase_add_test(tc_core, test_transpose_1);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_determinant_1) {
  matrix_t origin_1;
  int result = s21_create_matrix(2, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[1][0] = 3;
  origin_1.matrix[1][1] = 4;

  double double_result = 0;

  result = s21_determinant(&origin_1, &double_result);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(double_result, -2);
}

START_TEST(test_determinant_2) {
  matrix_t origin_1;
  int result = s21_create_matrix(3, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 3;
  origin_1.matrix[1][0] = 4;
  origin_1.matrix[1][1] = 5;
  origin_1.matrix[1][2] = 6;
  origin_1.matrix[2][0] = 7;
  origin_1.matrix[2][1] = 8;
  origin_1.matrix[2][2] = 9;

  double double_result = 0;

  result = s21_determinant(&origin_1, &double_result);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(double_result, 0);
}

START_TEST(test_determinant_3) {
  matrix_t origin_1;
  int result = s21_create_matrix(4, 4, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 1;
  origin_1.matrix[0][2] = 2;
  origin_1.matrix[0][3] = 3;

  origin_1.matrix[1][0] = 0;
  origin_1.matrix[1][1] = 1;
  origin_1.matrix[1][2] = 3;
  origin_1.matrix[1][3] = 1;

  origin_1.matrix[2][0] = 1;
  origin_1.matrix[2][1] = 1;
  origin_1.matrix[2][2] = 2;
  origin_1.matrix[2][3] = 2;

  origin_1.matrix[3][0] = 2;
  origin_1.matrix[3][1] = 1;
  origin_1.matrix[3][2] = 0;
  origin_1.matrix[3][3] = 1;

  double double_result = 0;

  result = s21_determinant(&origin_1, &double_result);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(double_result, -1);
}

START_TEST(test_determinant_4) {
  matrix_t origin_1;
  int result = s21_create_matrix(3, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  double double_result = 0;

  result = s21_determinant(&origin_1, &double_result);
  ck_assert_int_eq(result, 2);
}

START_TEST(test_determinant_5) {
  matrix_t *origin_1 = NULL;

  double double_result = 0;

  int result = s21_determinant(origin_1, &double_result);
  ck_assert_int_eq(result, 1);
}

START_TEST(test_determinant_6) {
  matrix_t origin_1;
  int result = s21_create_matrix(3, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.rows = -1;

  double double_result = 0;

  result = s21_determinant(&origin_1, &double_result);
  ck_assert_int_eq(result, 1);
}

Suite *determinant_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("determinant_matrix");
  tcase_add_test(tc_core, test_determinant_1);
  tcase_add_test(tc_core, test_determinant_2);
  tcase_add_test(tc_core, test_determinant_3);
  tcase_add_test(tc_core, test_determinant_4);
  tcase_add_test(tc_core, test_determinant_5);
  tcase_add_test(tc_core, test_determinant_6);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_calc_complements_1) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(3, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 3;
  origin_1.matrix[1][0] = 0;
  origin_1.matrix[1][1] = 4;
  origin_1.matrix[1][2] = 2;
  origin_1.matrix[2][0] = 5;
  origin_1.matrix[2][1] = 2;
  origin_1.matrix[2][2] = 1;

  result = s21_calc_complements(&origin_1, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_double_eq(result_matrix.matrix[0][0], 0);
  ck_assert_double_eq(result_matrix.matrix[0][1], 10);
  ck_assert_double_eq(result_matrix.matrix[0][2], -20);
  ck_assert_double_eq(result_matrix.matrix[1][0], 4);
  ck_assert_double_eq(result_matrix.matrix[1][1], -14);
  ck_assert_double_eq(result_matrix.matrix[1][2], 8);
  ck_assert_double_eq(result_matrix.matrix[2][0], -8);
  ck_assert_double_eq(result_matrix.matrix[2][1], -2);
  ck_assert_double_eq(result_matrix.matrix[2][2], 4);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_calc_complements_2) {
  matrix_t result_matrix;

  int result = s21_calc_complements(NULL, &result_matrix);
  ck_assert_int_eq(result, 1);
}

START_TEST(test_calc_complements_3) {
  matrix_t origin_1, result_matrix;

  int result = s21_create_matrix(3, 2, &origin_1);
  ck_assert_int_eq(result, 0);

  result = s21_calc_complements(&origin_1, &result_matrix);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&origin_1);
}

Suite *calc_complements_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("calc_complements_matrix");
  tcase_add_test(tc_core, test_calc_complements_1);
  tcase_add_test(tc_core, test_calc_complements_2);
  tcase_add_test(tc_core, test_calc_complements_3);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_inverse_1) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(3, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 2;
  origin_1.matrix[0][1] = 5;
  origin_1.matrix[0][2] = 7;

  origin_1.matrix[1][0] = 6;
  origin_1.matrix[1][1] = 3;
  origin_1.matrix[1][2] = 4;

  origin_1.matrix[2][0] = 5;
  origin_1.matrix[2][1] = -2;
  origin_1.matrix[2][2] = -3;

  result = s21_inverse_matrix(&origin_1, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_double_eq(result_matrix.matrix[0][0], 1);
  ck_assert_double_eq(result_matrix.matrix[0][1], -1);
  ck_assert_double_eq(result_matrix.matrix[0][2], 1);
  ck_assert_double_eq(result_matrix.matrix[1][0], -38);
  ck_assert_double_eq(result_matrix.matrix[1][1], 41);
  ck_assert_double_eq(result_matrix.matrix[1][2], -34);
  ck_assert_double_eq(result_matrix.matrix[2][0], 27);
  ck_assert_double_eq(result_matrix.matrix[2][1], -29);
  ck_assert_double_eq(result_matrix.matrix[2][2], 24);

  s21_remove_matrix(&origin_1);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_inverse_2) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(3, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  origin_1.matrix[0][0] = 1;
  origin_1.matrix[0][1] = 2;
  origin_1.matrix[0][2] = 3;

  origin_1.matrix[1][0] = 4;
  origin_1.matrix[1][1] = 5;
  origin_1.matrix[1][2] = 6;

  origin_1.matrix[2][0] = 7;
  origin_1.matrix[2][1] = 8;
  origin_1.matrix[2][2] = 9;

  result = s21_inverse_matrix(&origin_1, &result_matrix);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&origin_1);
}

START_TEST(test_inverse_3) {
  matrix_t origin_1, result_matrix;
  int result = s21_create_matrix(2, 3, &origin_1);
  ck_assert_int_eq(result, 0);

  result = s21_inverse_matrix(&origin_1, &result_matrix);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&origin_1);
}

START_TEST(test_inverse_4) {
  matrix_t result_matrix;

  int result = s21_inverse_matrix(NULL, &result_matrix);
  ck_assert_int_eq(result, 1);
}

START_TEST(test_inverse_5) {
  matrix_t origin, result_matrix;
  int result = s21_create_matrix(2, 2, &origin);
  ck_assert_int_eq(result, 0);

  origin.matrix[0][0] = 3;
  origin.matrix[0][1] = 4;
  origin.matrix[1][0] = 5;
  origin.matrix[1][1] = 7;

  result = s21_inverse_matrix(&origin, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_double_eq(result_matrix.matrix[0][0], 7);
  ck_assert_double_eq(result_matrix.matrix[0][1], -4);
  ck_assert_double_eq(result_matrix.matrix[1][0], -5);
  ck_assert_double_eq(result_matrix.matrix[1][1], 3);

  s21_remove_matrix(&origin);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_inverse_6) {
  matrix_t origin, result_matrix;
  int result = s21_create_matrix(1, 1, &origin);
  ck_assert_int_eq(result, 0);

  origin.matrix[0][0] = 1;

  result = s21_inverse_matrix(&origin, &result_matrix);
  ck_assert_int_eq(result, 0);

  ck_assert_double_eq(result_matrix.matrix[0][0], 1);

  s21_remove_matrix(&origin);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    m.matrix[0][0] = 5;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(code, ERROR_0);
    s21_remove_matrix(&result);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(test_zero_det) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    s21_remove_matrix(&m);
    ck_assert_int_eq(code, ERROR_2);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, ERROR_1);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, ERROR_2);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(test_normal) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (!codec1) codec2 = s21_create_matrix(3, 3, &expected);

  if (!codec1 && !codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

    ck_assert_int_eq(code, ERROR_0);
    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *inverse_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("inverse_matrix");
  tcase_add_test(tc_core, test_inverse_1);
  tcase_add_test(tc_core, test_inverse_2);
  tcase_add_test(tc_core, test_inverse_3);
  tcase_add_test(tc_core, test_inverse_4);
  tcase_add_test(tc_core, test_inverse_5);
  tcase_add_test(tc_core, test_inverse_6);

  tcase_add_test(tc_core, test_normal);
  tcase_add_test(tc_core, test_not_sqare);
  tcase_add_test(tc_core, test_zero_det);
  tcase_add_test(tc_core, test_incorrect);
  tcase_add_test(tc_core, test_one_by_one);
  suite_add_tcase(s, tc_core);

  return s;
}

int number_of_tests_failed(void) {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;

  s = create_matrix_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = remove_matrix_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = eq_matrix_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = sum_matrix_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = sub_matrix_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = mult_matrix_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = mult_number_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = transpose_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = determinant_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = calc_complements_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = inverse_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  return number_failed;
}

int main() {
  int number_failed = number_of_tests_failed();
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
