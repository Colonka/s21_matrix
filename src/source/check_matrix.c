#include "s21_matrix.h"

int check_matrix(matrix_t *A) {
  int code = OK;
  if (A->columns <= 0 || A->rows <= 0 || !A->matrix) {
    code = FAILURE;
  }
  return code;
}