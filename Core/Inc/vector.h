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

#ifndef IMUMATH_VECTOR_H
#define IMUMATH_VECTOR_H

#include <math.h>
#include <stdint.h>
#include <string.h>

#define VECTOR_SIZE 3

typedef struct {
  double p_vec[VECTOR_SIZE];
} Vector;

static inline void vector_init(Vector *v, double a, double b, double c) {
  v->p_vec[0] = a;
  v->p_vec[1] = b;
  v->p_vec[2] = c;
}

static inline void vector_zero(Vector *v) {
  memset(v->p_vec, 0, sizeof(double) * VECTOR_SIZE);
}

static inline double vector_magnitude(const Vector *v) {
  double res = 0;
  for (int i = 0; i < VECTOR_SIZE; i++) {
    res += v->p_vec[i] * v->p_vec[i];
  }
  return sqrt(res);
}

static inline void vector_normalize(Vector *v) {
  double mag = vector_magnitude(v);
  if (mag == 0.0)
    return;
  for (int i = 0; i < VECTOR_SIZE; i++) {
    v->p_vec[i] /= mag;
  }
}

static inline double vector_dot(const Vector *v1, const Vector *v2) {
  double ret = 0;
  for (int i = 0; i < VECTOR_SIZE; i++) {
    ret += v1->p_vec[i] * v2->p_vec[i];
  }
  return ret;
}

static inline void vector_cross(const Vector *v1, const Vector *v2,
                                Vector *result) {
  result->p_vec[0] = v1->p_vec[1] * v2->p_vec[2] - v1->p_vec[2] * v2->p_vec[1];
  result->p_vec[1] = v1->p_vec[2] * v2->p_vec[0] - v1->p_vec[0] * v2->p_vec[2];
  result->p_vec[2] = v1->p_vec[0] * v2->p_vec[1] - v1->p_vec[1] * v2->p_vec[0];
}

static inline void vector_scale(Vector *v, double scalar) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    v->p_vec[i] *= scalar;
  }
}

static inline void vector_invert(Vector *v) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    v->p_vec[i] = -v->p_vec[i];
  }
}

static inline void vector_add(const Vector *v1, const Vector *v2,
                              Vector *result) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    result->p_vec[i] = v1->p_vec[i] + v2->p_vec[i];
  }
}

static inline void vector_subtract(const Vector *v1, const Vector *v2,
                                   Vector *result) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    result->p_vec[i] = v1->p_vec[i] - v2->p_vec[i];
  }
}

static inline void vector_to_degrees(Vector *v) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    v->p_vec[i] *= 57.2957795131; // 180/pi
  }
}

static inline void vector_to_radians(Vector *v) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    v->p_vec[i] *= 0.01745329251; // pi/180
  }
}

#endif // IMUMATH_VECTOR_H
