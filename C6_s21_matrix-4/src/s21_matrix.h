#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum { ERROR_0 = 0, ERROR_1, ERROR_2 };

enum { FAILURE = 0, SUCCESS };
// #define SUCCESS 1
// #define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);  // tests +
void s21_remove_matrix(matrix_t *A);                             // tests +
int s21_eq_matrix(matrix_t *A, matrix_t *B);                     // tests +

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // tests +
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // tests +

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif
