
#include "s21_matrix.h"

int check_matrix_for_null(matrix_t *A, matrix_t *B) {
  int return_value = ERROR_0;

  if (A != NULL && B != NULL) {
    if (A->matrix == NULL || B->matrix == NULL) {
      return_value = ERROR_1;
    }
  } else {
    return_value = ERROR_1;
  }

  return return_value;
}

int check_matrix_for_equality(matrix_t *A, matrix_t *B) {
  int return_value = ERROR_0;

  if (A->columns == B->columns) {
    if (A->rows != B->rows) {
      return_value = ERROR_2;
    }
  } else {
    return_value = ERROR_2;
  }

  //    printf("ERROR = %d\n", return_value);

  return return_value;
}

int check_matrix_for_minus(matrix_t *A, matrix_t *B) {
  int return_value = ERROR_0;

  //    printf("%d %d\n", A -> rows, A -> columns);
  //    printf("%d %d\n", B -> rows, B -> columns);

  if (A->rows < 1 || A->columns < 1) {
    return_value = ERROR_1;
  } else if (B->rows < 1 || B->columns < 1) {
    return_value = ERROR_1;
  }

  return return_value;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_value = ERROR_0;
  if (rows < 1 || columns < 1) {
    return_value = ERROR_1;
  } else if (result == NULL) {
    return_value = ERROR_1;
  } else {
    result->matrix = calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
  }
  return return_value;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      A->rows = 0;
      A->columns = 0;
      free(A->matrix);
      A->matrix = NULL;
    }
  }
}

int eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = SUCCESS;

  for (int i = 0; i < A->rows && return_value != FAILURE; i++) {
    for (int j = 0; j < A->columns && return_value != FAILURE; j++) {
      double num_1 = A->matrix[i][j];
      double num_2 = B->matrix[i][j];
      if (fabs(num_1 - num_2) > 1e-6) {
        return_value = FAILURE;
      }
    }
  }

  return return_value;
}

// 1 — неправильная матрица
// 2 – неправильное вычисление матрицы

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = FAILURE;

  if (A != NULL && B != NULL) {
    if (A->matrix != NULL && B->matrix != NULL) {
      if (A->rows == B->rows && A->rows >= 1) {
        if (A->columns == B->columns && A->columns >= 1) {
          return_value = eq_matrix(A, B);
        }
      }
    }
  }

  return return_value;
}

void sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
}
// добавить обработку ошибок 1 и 2, спросить у людей
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = ERROR_1;

  if (!check_matrix_for_null(A, B)) {
    if (!check_matrix_for_minus(A, B)) {
      if (!check_matrix_for_equality(A, B)) {
        return_value = s21_create_matrix(A->rows, A->columns, result);
        sum_matrix(A, B, result);
      } else {
        return_value = ERROR_2;
      }
    }
  }

  return return_value;
}

void sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = ERROR_1;

  if (!check_matrix_for_null(A, B)) {
    //        printf("goog\n");
    if (!check_matrix_for_minus(A, B)) {
      //            printf("goog\n");
      if (!check_matrix_for_equality(A, B)) {
        //                printf("goog\n");
        return_value = s21_create_matrix(A->rows, A->columns, result);
        sub_matrix(A, B, result);
      } else {
        return_value = ERROR_2;
      }
    }
  }

  return return_value;
}

double get_sum_rows_and_columns(matrix_t *A, matrix_t *B, int row, int column) {
  double result = 0;

  for (int i = 0; i < A->columns; i++) {
    result += A->matrix[row][i] * B->matrix[i][column];
  }

  return result;
}

void mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = get_sum_rows_and_columns(A, B, i, j);
    }
  }
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = ERROR_1;
  //    printf("%d %d\n", A -> rows, B -> columns);
  if (!check_matrix_for_null(A, B)) {
    if (!check_matrix_for_minus(A, B)) {
      if (A->columns == B->rows) {
        return_value = s21_create_matrix(A->rows, B->columns, result);
        mult_matrix(A, B, result);
      } else {
        return_value = ERROR_2;
      }
    }
  }

  return return_value;
}

void mult_number(matrix_t *A, double number, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_value = ERROR_1;

  if (A != NULL) {
    if (A->matrix != NULL) {
      if (A->rows > 0 && A->columns > 0) {
        return_value = s21_create_matrix(A->rows, A->columns, result);
        mult_number(A, number, result);
      }
    }
  }

  return return_value;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_value = ERROR_1;

  if (A != NULL) {
    if (A->matrix != NULL) {
      if (A->rows > 0 && A->columns > 0) {
        return_value = s21_create_matrix(A->columns, A->rows, result);
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[j][i] = A->matrix[i][j];
          }
        }
      }
    }
  }

  return return_value;
}

double minor(matrix_t A, matrix_t *tmp, int row, int column) {
  double result = 0;
  int s = 0, st = 0;

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (i != row && j != column) {
        tmp->matrix[s][st] = A.matrix[i][j];
        st++;
      }
    }
    if (st == A.rows - 1) {
      s++;
      st = 0;
    }
  }

  s21_determinant(tmp, &result);

  return result;
}

int determinant(matrix_t *A, double *result) {
  int return_value = ERROR_0;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    matrix_t tmp;
    return_value = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int j = 0; j < A->columns; j++) {
      *result += pow(-1, j) * A->matrix[0][j] * minor(*A, &tmp, 0, j);
    }
    s21_remove_matrix(&tmp);
  }

  return return_value;
}

int s21_determinant(matrix_t *A, double *result) {
  int return_value = ERROR_1;
  *result = 0;

  // add checks for different cases

  if (A != NULL) {
    if (A->matrix != NULL) {
      if (A->rows > 0 && A->columns > 0) {
        if (A->rows == A->columns) {
          return_value = determinant(A, result);
        } else {
          return_value = ERROR_2;
        }
      }
    }
  }

  return return_value;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_value = ERROR_1;
  if (A != NULL) {
    if (A->matrix != NULL) {
      if (A->rows > 0 && A->columns > 0) {
        if (A->rows == A->columns && A->rows == 1) {
          return_value = s21_create_matrix(A->rows, A->columns, result);
          result->matrix[0][0] = A->matrix[0][0];
        } else if (A->rows == A->columns) {
          matrix_t tmp;
          return_value = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
          return_value = s21_create_matrix(A->rows, A->columns, result);

          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              result->matrix[i][j] = pow(-1, i + j) * minor(*A, &tmp, i, j);
            }
          }
          s21_remove_matrix(&tmp);
        } else {
          return_value = ERROR_2;
        }
      }
    }
  }
  return return_value;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double determinant = 0;
  int return_value = s21_determinant(A, &determinant);
  if (return_value == 0) {
    if (determinant != 0) {
      if (A->rows == 1) {
        return_value = s21_create_matrix(A->rows, A->columns, result);
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        matrix_t tmp;
        return_value = s21_calc_complements(A, result);
        return_value = s21_transpose(result, &tmp);
        s21_remove_matrix(result);
        return_value = s21_mult_number(&tmp, 1 / determinant, result);
        s21_remove_matrix(&tmp);
      }
    } else {
      return_value = ERROR_2;
    }
  }

  return return_value;
}
