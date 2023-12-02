#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// @brief matrix info
typedef struct matrix_struct {
  double **matrix;  ///< pointer to matrix
  int rows;         ///< rows amount
  int columns;      ///< columns amount
} matrix_t;

#define SUCCESS 0
#define FAILURE 1
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

// ADDITIONAL FUNCTIONS

/**
 * @brief Matrix allocation
 * @param result pointer to allocated matrix
 * @return error code 0 - ok, 1 - err
 */
int alloc_matrix(matrix_t *result);

/**
 * @brief Matrix allocation
 * @param A pointer to checking matrix
 * @return error code 0 - ok, 1 - err
 */
int check_matrix(matrix_t *A);

/**
 * @brief Minor matrix creating
 * @param A pointer to source matrix
 * @param minor pointer to minor matrix
 * @param row deleting line number
 * @param row deleting column number
 */
void create_minor_matrix(matrix_t *A, matrix_t *minor, int row, int column);

// CREATING MATRIX

/**
 * @brief Matrix creating
 * @param rows rows number
 * @param columns columns number
 * @param result pointer to created matrix
 * @return error code 0 - ok, 1 - err
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

// REMOVE MATRIX

/**
 * @brief Matrix removing
 * @param  A pointer to removing matrix
 */
void s21_remove_matrix(matrix_t *A);

// EQUALIZE MATRIX

/**
 * @brief Matrix comparison
 * @param  A pointer to comparising matrix
 * @param  B pointer to comparising matrix
 * @return 1 - is equal, 0 - isn't equal
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// SUM MATRIX

/**
 * @brief Add matrixs
 * @param  A pointer to matrix
 * @param  B pointer to matrix
 * @param  result pointer to matrix (addition result)
 * @return error code 0 - ok, 1 - incorrect matrix, 2 - calc error
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// SUB MATRIX

/**
 * @brief Matrixs substruction
 * @param  A pointer to matrix
 * @param  B pointer to matrix
 * @param  result pointer to matrix (substruction result)
 * @return error code
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// MULT MATRIX ON NUMBER

/**
 * @brief Matrix multiplication on number
 * @param  A pointer to matrix
 * @param  B number
 * @param  result pointer to matrix (mult result)
 * @return error code
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// MULT MATRIX ON MATRIX

/**
 * @brief Matrix multiplication on matrix
 * @param  A pointer to matrix
 * @param  B pointer to matrix
 * @param  result pointer to matrix (mult result)
 * @return error code
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// TRANSPOSE MATRIX

/**
 * @brief Matrix transpose
 * @param  A pointer to matrix
 * @param  result pointer to matrix (transpose result)
 * @return error code
 */
int s21_transpose(matrix_t *A, matrix_t *result);

// MINOR MATRIX

/**
 * @brief Matrix calc_comlements computing
 * @param  A pointer to matrix
 * @param  result pointer to matrix result
 * @return error code
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

// DETERMINANT MATRIX

/**
 * @brief Matrix determinant computing
 * @param  A pointer to matrix
 * @param  result pointer to matrix result
 * @return error code
 */
int s21_determinant(matrix_t *A, double *result);

// INVERSE MATRIX

/**
 * @brief Matrix inversing
 * @param  A pointer to matrix
 * @param  result pointer to inverted matrix
 * @return error code
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif