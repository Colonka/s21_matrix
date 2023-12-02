#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (!check_matrix(A) && !check_matrix(B)) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      double tmp = 0.0;
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          for (int y = 0; y < A->columns; y++) {
            tmp += A->matrix[i][y] * B->matrix[y][j];
          }
          result->matrix[i][j] = tmp;
          tmp = 0.0;
        }
      }
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}