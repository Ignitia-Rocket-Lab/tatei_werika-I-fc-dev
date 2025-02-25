//  Inertial Measurement Unit Maths Library
//
//  Copyright 2013-2021 Sam Cowen <samuel.cowen@camelsoftware.com>
//  Bug fixes and cleanups by Gé Vissers (gvissers@gmail.com)
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

typedef struct {
  double cell_data[N * N];
} Matrix;

void matrix_minor(Matrix *result, const Matrix *m, int row, int col);

void matrix_init(Matrix *m) { memset(m->cell_data, 0, N * N * sizeof(double)); }

void matrix_copy(Matrix *dest, const Matrix *src) {
  memcpy(dest->cell_data, src->cell_data, N * N * sizeof(double));
}

double matrix_get(const Matrix *m, int i, int j) {
  return m->cell_data[i * N + j];
}

double *matrix_get_ptr(Matrix *m, int i, int j) {
  return &m->cell_data[i * N + j];
}

void matrix_set(Matrix *m, int i, int j, double value) {
  m->cell_data[i * N + j] = value;
}

void matrix_add(Matrix *result, const Matrix *a, const Matrix *b) {
  for (int i = 0; i < N * N; i++) {
    result->cell_data[i] = a->cell_data[i] + b->cell_data[i];
  }
}

void matrix_sub(Matrix *result, const Matrix *a, const Matrix *b) {
  for (int i = 0; i < N * N; i++) {
    result->cell_data[i] = a->cell_data[i] - b->cell_data[i];
  }
}

void matrix_scalar_mult(Matrix *result, const Matrix *m, double scalar) {
  for (int i = 0; i < N * N; i++) {
    result->cell_data[i] = m->cell_data[i] * scalar;
  }
}

void matrix_mult(Matrix *result, const Matrix *a, const Matrix *b) {
  Matrix temp;
  matrix_init(&temp);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      double sum = 0;
      for (int k = 0; k < N; k++) {
        sum += matrix_get(a, i, k) * matrix_get(b, k, j);
      }
      matrix_set(&temp, i, j, sum);
    }
  }
  matrix_copy(result, &temp);
}

void matrix_transpose(Matrix *result, const Matrix *m) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix_set(result, j, i, matrix_get(m, i, j));
    }
  }
}

double matrix_determinant(const Matrix *m) {
  // Determinant calculation assumes N > 1
  if (N == 1)
    return matrix_get(m, 0, 0);
  double det = 0.0, sign = 1.0;
  for (int i = 0; i < N; i++, sign = -sign) {
    Matrix minor;
    matrix_minor(&minor, m, 0, i);
    det += sign * matrix_get(m, 0, i) * matrix_determinant(&minor);
  }
  return det;
}

void matrix_minor(Matrix *result, const Matrix *m, int row, int col) {
  int index = 0;
  for (int i = 0; i < N; i++) {
    if (i == row)
      continue;
    for (int j = 0; j < N; j++) {
      if (j == col)
        continue;
      result->cell_data[index++] = matrix_get(m, i, j);
    }
  }
}

void matrix_invert(Matrix *result, const Matrix *m) {
  double det = matrix_determinant(m);
  if (det == 0) {
    printf("Matrix is singular and cannot be inverted.\n");
    return;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      Matrix minor;
      matrix_minor(&minor, m, j, i);
      double value = matrix_determinant(&minor) / det;
      if ((i + j) % 2 == 1)
        value = -value;
      matrix_set(result, i, j, value);
    }
  }
}

double matrix_trace(const Matrix *m) {
  double tr = 0.0;
  for (int i = 0; i < N; i++) {
    tr += matrix_get(m, i, i);
  }
  return tr;
}

#endif // __MATRIX_H__
