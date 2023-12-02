#include "s21_matrix.h"

void s21_find_determinant(matrix_t* A, double* result);

int s21_determinant(matrix_t* A, double* result) {
  int status = OK;
  if (!check_matrix(A)) {
    if (A->rows == A->columns) {
      s21_find_determinant(A, result);
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

void s21_find_determinant(matrix_t* A, double* result) {
  double minor_det = 0.0;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result = (A->matrix[0][0] * A->matrix[1][1]) -
              (A->matrix[0][1] * A->matrix[1][0]);
  } else {
    matrix_t minor = {NULL, 0, 0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int j = 0, sign = 1; j < A->columns; j++, sign *= -1) {
      minor_det = 0.0;
      create_minor_matrix(A, &minor, 0, j);
      s21_find_determinant(&minor, &minor_det);
      *result += sign * A->matrix[0][j] * minor_det;
    }
    s21_remove_matrix(&minor);
  }
}
