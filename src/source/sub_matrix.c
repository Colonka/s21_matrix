#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (!check_matrix(A) && !check_matrix(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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