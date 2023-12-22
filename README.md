# s21_matrix

Implementation of the s21_matrix.h library in C programming language.

## Introduction

In this project I've implemented my own library for processing numerical matrices in the C programming language.

## Instructions for running

Include s21_matrix.h in your file and link libs21_matrix.a while compilation of your source files.

`#include "<Directory where the header resides>/s21_matrix.h"`

`-L<Directory where the library resides> -l<library name>`

## Instruction for reinstalling

Being in s21_matrix/src folder run command `make` in terminal that create static library s21_matrix. Then include s21_matrix.h in your file and link libs21_matrix.a while compilation of your source files.

`#include "<Directory where the header resides>/s21_matrix.h"`

`-L<Directory where the library resides> -l<library name>`

## Instruction for testing

Being in s21_matrix/src folder run command `make test`

*Note: you need installed `pkg-config` for choosing flags for check.h library linking 

## Instruction for gcovr test coverage

Being in s21_matrix/src folder run command `make gcovr_report`

## Documentation

To open library documentation run command `make docs` in terminal being in s21_matrix/src folder.

### Matrix structure in C language:

```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

## Matrix operations

All operations (except matrix comparison) are return the resulting code:
- 0 - OK
- 1 - Error, incorrect matrix
- 2 - Calculation error (mismatched matrix sizes; matrix for which calculations cannot be performed, etc.)

### Creating matrices (create_matrix)

```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
```

### Cleaning of matrices (remove_matrix)

```c
void s21_remove_matrix(matrix_t *A);
```

### Matrix comparison (eq_matrix)

```c
#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);
```

### Adding (sum_matrix) and subtracting matrices (sub_matrix)

```c
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Matrix multiplication by scalar (mult_number). Multiplication of two matrices (mult_matrix)

```c
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Matrix transpose (transpose)

```c
int s21_transpose(matrix_t *A, matrix_t *result);
```

### Minor of matrix and matrix of algebraic complements (calc_complements)
```c
int s21_calc_complements(matrix_t *A, matrix_t *result);
```

### Matrix determinant

```c
int s21_determinant(matrix_t *A, double *result);
```

### Inverse of the matrix (inverse_matrix)

```c
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```
