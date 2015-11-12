//
// Herb Yang, Oct. 2008
// some constants, types and macros are defined in here.
//

#ifndef MATHTYPES_H
#define MATHTYPES_H

#include <math.h>

typedef double RTfloat;
// =============================================================
//   Generally useful macros

#define MAX(a,b)  (((a) < (b))?(b):(a))
#define MIN(a,b)  (((a) < (b))?(a):(b))

// ==============================================================
//    A series of macros for using w/ floats -- IsZero, etc

// The value of infinity
#define F_INFINITY 9e99

// Epsilon for round-off errors.
//#define F_EPSILON 1.0e-12
#define F_EPSILON 1.0e-12

// The minimum distance which we'll assume objects are apart
// -- used in ray bouncing, and light calculations to avoid a ray intersecting
//  the object it just bounced off of.
#define MIN_OBJ_DIST 1e-4

// Is the given float zero?
#define F_IsZero(b) ((-F_EPSILON < b) && (b < F_EPSILON))

// Are the two given floats equal?
#define F_EQ(a,b) (fabs((a)-(b)) < F_EPSILON)

// returns the result of a<(b+F_EPSILON)
#define F_LT(a,b) ((a)<((b)+F_EPSILON))

// returns the result of a>(b+F_EPSILON)
#define F_GT(a,b) ((a)>((b)+F_EPSILON))


#endif
