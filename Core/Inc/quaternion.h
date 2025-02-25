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

#ifndef IMUMATH_QUATERNION_H
#define IMUMATH_QUATERNION_H

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

typedef struct {
  double w, x, y, z;
} Quaternion;

// Constructor-like functions
static inline Quaternion quaternion_init() {
  return (Quaternion){1.0, 0.0, 0.0, 0.0};
}

static inline Quaternion quaternion_new(double w, double x, double y,
                                        double z) {
  return (Quaternion){w, x, y, z};
}

// Magnitude
static inline double quaternion_magnitude(const Quaternion *q) {
  return sqrt(q->w * q->w + q->x * q->x + q->y * q->y + q->z * q->z);
}

// Normalize
static inline void quaternion_normalize(Quaternion *q) {
  double mag = quaternion_magnitude(q);
  q->w /= mag;
  q->x /= mag;
  q->y /= mag;
  q->z /= mag;
}

// Conjugate
static inline Quaternion quaternion_conjugate(const Quaternion *q) {
  return quaternion_new(q->w, -q->x, -q->y, -q->z);
}

// Quaternion multiplication
static inline Quaternion quaternion_multiply(const Quaternion *q1,
                                             const Quaternion *q2) {
  return quaternion_new(
      q1->w * q2->w - q1->x * q2->x - q1->y * q2->y - q1->z * q2->z,
      q1->w * q2->x + q1->x * q2->w + q1->y * q2->z - q1->z * q2->y,
      q1->w * q2->y - q1->x * q2->z + q1->y * q2->w + q1->z * q2->x,
      q1->w * q2->z + q1->x * q2->y - q1->y * q2->x + q1->z * q2->w);
}

// Quaternion scaling
static inline Quaternion quaternion_scale(const Quaternion *q, double scalar) {
  return quaternion_new(q->w * scalar, q->x * scalar, q->y * scalar,
                        q->z * scalar);
}

// Quaternion addition
static inline Quaternion quaternion_add(const Quaternion *q1,
                                        const Quaternion *q2) {
  return quaternion_new(q1->w + q2->w, q1->x + q2->x, q1->y + q2->y,
                        q1->z + q2->z);
}

// Quaternion subtraction
static inline Quaternion quaternion_subtract(const Quaternion *q1,
                                             const Quaternion *q2) {
  return quaternion_new(q1->w - q2->w, q1->x - q2->x, q1->y - q2->y,
                        q1->z - q2->z);
}

#endif // IMUMATH_QUATERNION_H
