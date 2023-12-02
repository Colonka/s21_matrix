#include "s21_matrix.h"

#define DELTA 1e-6

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = 1;
  if (!check_matrix(A) && !check_matrix(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > DELTA) {
            result = 0;
            break;
          }
        }
        if (!result) break;
      }
    } else {
      result = 0;
    }
  } else {
    result = 0;
  }
  return result;
}