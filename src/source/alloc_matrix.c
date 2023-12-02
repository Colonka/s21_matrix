#include "s21_matrix.h"

int alloc_matrix(matrix_t *result) {
  int status = SUCCESS;
  result->matrix = (double **)malloc(result->rows * sizeof(double *));
  if (result->matrix) {
    for (int i = 0; i < result->rows; i++) {
      result->matrix[i] = (double *)malloc(result->columns * sizeof(double));
      if (result->matrix[i]) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = 0.0;
        }
      } else {
        status = FAILURE;
        break;
      }
    }
  } else {
    status = FAILURE;
  }
  return status;
}