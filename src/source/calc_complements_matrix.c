#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (!check_matrix(A)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      matrix_t minor;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          double minor_det = 0.0;
          create_minor_matrix(A, &minor, i, j);
          s21_determinant(&minor, &minor_det);
          if ((i + j) % 2 == 0) {
            result->matrix[i][j] = minor_det;
          } else {
            result->matrix[i][j] = minor_det * (-1);
          }
        }
      }
      s21_remove_matrix(&minor);
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}