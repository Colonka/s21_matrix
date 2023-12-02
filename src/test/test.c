#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../source/s21_matrix.h"

START_TEST(create_matrix) {
  matrix_t result;
  int rows = 2, columns = 10;
  int exit_code = s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(0, exit_code);
  s21_remove_matrix(&result);

  //
  rows = 2;
  columns = 2;
  exit_code = s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(0, exit_code);
  s21_remove_matrix(&result);

  //

  rows = 0;
  columns = 2;
  exit_code = s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(1, exit_code);
  s21_remove_matrix(&result);

  //

  rows = 0;
  columns = 0;
  exit_code = s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(1, exit_code);
  s21_remove_matrix(&result);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(equal_matrix) {
  matrix_t A, B;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(4, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  //

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  //

  s21_create_matrix(10, 5, &A);
  s21_create_matrix(10, 5, &B);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  //

  s21_create_matrix(10, 50, &A);
  s21_create_matrix(10, 50, &B);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 50; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  //

  s21_create_matrix(10, 50, &A);
  s21_create_matrix(10, 50, &B);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 50; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  //

  s21_create_matrix(100, 500, &A);
  s21_create_matrix(100, 500, &B);
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 500; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  //

  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  //

  s21_create_matrix(1, 2, &A);
  B.matrix = NULL;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);

  //

  s21_create_matrix(1, 2, &A);
  s21_create_matrix(0, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  //

  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(sum_matrix) {
  matrix_t A, B, result;
  A.matrix = NULL, B.matrix = NULL;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(4, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL, B.matrix = NULL;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(sub_matrix) {
  matrix_t A, B, result;
  A.matrix = NULL, B.matrix = NULL;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] - B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] - B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] - B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(4, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL, B.matrix = NULL;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(mult_number_matrix) {
  matrix_t A, result;
  int rows = 5, columns = 5;
  double number = (double)(rand()) / RAND_MAX;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j],
                              1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  number = (double)(rand()) / RAND_MAX;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j],
                              1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = 5;
  columns = 5;
  number = (double)(rand()) / RAND_MAX;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j],
                              1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL;
  number = (double)(rand()) / RAND_MAX;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  number = (double)(rand()) / RAND_MAX;
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(mult_matrix) {
  matrix_t A, B, result;
  int Arows = 3, Acolumns = 5;
  int Brows = 5, Bcolumns = 6;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  Arows = 30;
  Acolumns = 144;
  Brows = 144;
  Bcolumns = 27;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  Arows = 4;
  Acolumns = 10;
  Brows = 13;
  Bcolumns = 27;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  Arows = 3;
  Acolumns = 10;
  Brows = 14;
  Bcolumns = 2;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL;
  B.matrix = NULL;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(transpose_matrix) {
  matrix_t A, result;
  int rows = 3, columns = 5;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = 31;
  columns = 52;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = 51;
  columns = 5;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL;
  ck_assert_int_eq(s21_transpose(&A, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  matrix_t result_tmp;
  rows = 3;
  columns = 2;
  int sum = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_create_matrix(columns, rows, &result_tmp);
  result_tmp.matrix[0][0] = 1;
  result_tmp.matrix[0][1] = 2;
  result_tmp.matrix[0][2] = 3;
  result_tmp.matrix[1][0] = 4;
  result_tmp.matrix[1][1] = 5;
  result_tmp.matrix[1][2] = 6;
  s21_transpose(&A, &result);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      if (fabs(result_tmp.matrix[i][j] - result.matrix[i][j]) > 1e-8) {
        sum++;
      }
    }
  }
  ck_assert_int_eq(sum, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_tmp);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(calc_complements_matrix) {
  matrix_t A, result;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = 6;
  columns = 6;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = 10;
  columns = 7;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL;
  result.matrix = NULL;
  ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(determinant_matrix) {
  matrix_t A;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  double result = 0.0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), SUCCESS);
  s21_remove_matrix(&A);

  //

  rows = 6;
  columns = 6;
  s21_create_matrix(rows, columns, &A);
  result = 0.0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), SUCCESS);
  s21_remove_matrix(&A);

  //

  rows = 10;
  columns = 7;
  s21_create_matrix(rows, columns, &A);
  result = 0.0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);

  //

  A.matrix = NULL;
  result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);

  //

  rows = 4;
  columns = 4;
  s21_create_matrix(rows, columns, &A);
  result = 0.0;
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 6;
  A.matrix[0][3] = 7;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 12;
  A.matrix[1][2] = 11;
  A.matrix[1][3] = 9;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 4;
  A.matrix[2][3] = 5;
  A.matrix[3][0] = 6;
  A.matrix[3][1] = 9;
  A.matrix[3][2] = 10;
  A.matrix[3][3] = 4;
  s21_determinant(&A, &result);
  ck_assert_double_eq(result, -135);
  s21_remove_matrix(&A);

  //

  matrix_t result_tmp, result_true;
  rows = 3;
  columns = 3;
  int sum = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result_true);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  result_true.matrix[0][0] = 0;
  result_true.matrix[0][1] = 10;
  result_true.matrix[0][2] = -20;
  result_true.matrix[1][0] = 4;
  result_true.matrix[1][1] = -14;
  result_true.matrix[1][2] = 8;
  result_true.matrix[2][0] = -8;
  result_true.matrix[2][1] = -2;
  result_true.matrix[2][2] = 4;
  s21_calc_complements(&A, &result_tmp);
  for (int i = 0; i < result_tmp.rows; i++) {
    for (int j = 0; j < result_tmp.columns; j++) {
      if (fabs(result_tmp.matrix[i][j] - result_true.matrix[i][j]) > 1e-8) {
        sum++;
      }
    }
  }
  ck_assert_int_eq(sum, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result_true);
  s21_remove_matrix(&result_tmp);
}
END_TEST

//////////////////////////////////////////////////////////////////

START_TEST(inverse_matrix) {
  matrix_t A, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = 6;
  columns = 6;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = 10;
  columns = 7;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  rows = -10;
  columns = 7;
  s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  A.matrix = NULL;
  result.matrix = NULL;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  //

  matrix_t result_true;
  rows = 3;
  columns = 3;
  int sum = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result_true);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  result_true.matrix[0][0] = 1;
  result_true.matrix[0][1] = -1;
  result_true.matrix[0][2] = 1;
  result_true.matrix[1][0] = -38;
  result_true.matrix[1][1] = 41;
  result_true.matrix[1][2] = -34;
  result_true.matrix[2][0] = 27;
  result_true.matrix[2][1] = -29;
  result_true.matrix[2][2] = 24;
  s21_inverse_matrix(&A, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (fabs(result.matrix[i][j] - result_true.matrix[i][j]) > 1e-8) {
        sum++;
      }
    }
  }
  ck_assert_int_eq(sum, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result_true);
  s21_remove_matrix(&result);
}
END_TEST

//////////////////////////////////////////////////////////////////

Suite *matrix_suite(void) {
  Suite *s = suite_create("Matrix_testcase");
  TCase *tc_matrix = tcase_create("Core");

  suite_add_tcase(s, tc_matrix);
  tcase_add_test(tc_matrix, create_matrix);
  tcase_add_test(tc_matrix, equal_matrix);
  tcase_add_test(tc_matrix, sum_matrix);
  tcase_add_test(tc_matrix, sub_matrix);
  tcase_add_test(tc_matrix, mult_number_matrix);
  tcase_add_test(tc_matrix, mult_matrix);
  tcase_add_test(tc_matrix, transpose_matrix);
  tcase_add_test(tc_matrix, calc_complements_matrix);
  tcase_add_test(tc_matrix, determinant_matrix);
  tcase_add_test(tc_matrix, inverse_matrix);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = matrix_suite();
  sr = srunner_create(s);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}