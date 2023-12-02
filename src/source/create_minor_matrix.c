#include "s21_matrix.h"

void create_minor_matrix(matrix_t* A, matrix_t* minor, int row, int column) {
  int i_tmp = 0;
  int j_tmp = 0;
  for (int i = 0; i < A->rows; i++) {
    j_tmp = 0;
    if (i != row) {
      for (int j = 0; j < A->columns; j++) {
        if (j != column) {
          minor->matrix[i_tmp][j_tmp] = A->matrix[i][j];
          j_tmp++;
        }
      }
      i_tmp++;
    }
  }
}
