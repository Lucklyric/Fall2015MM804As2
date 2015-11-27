//
// Author: Herb Yang, March 9, 2010
//
#ifndef RAY_H
#define RAY_H
#include "mathtypes.h"
#include "vector3.h"
class Ray {
public:
    Vector3 o; // origin of the ray
    Vector3 d; // direction of travel - should be normalized
    Vector3 getPosition(const RTfloat& k);// get the coordinates with a value of k (the parameter value)
    Vector3 reflectedDirection( const Vector3& normal);// given the normal, get the reflected light direction
    RTfloat distance(const Vector3& point);// get the distance of the point from the origin of the ray
    friend Ray createRay(const Vector3& to, const Vector3& from);// create a ray from "from" to "to".
};
#endif
