/*
Author: Herb Yang, March 9, 2010
*/

#ifndef SPHERE_H
#define SPHERE_H

#include "mathtypes.h"
#include "color.h"
#include "vector3.h"
#include "ray.h"
#include "geomObj.h"
#include <vector>
class Sphere : public geomObj {// see the definition of geomObj for more explanation
public:
    RTfloat rad; // the sphere's radius
    Vector3 center; // the center of the sphere
    Color diffuse, ambient, specular;
    RTfloat specularExp;
    Vector3 getNormal(Vector3 *point);// Return the normal vector for the given point on the surface
    //  Find and return, in k, the earliest intersection point, in the
    // range [k0,k1), along the given ray. Returns 1 if such a t exists,
    // false otherwise
    bool intersect(RTfloat *k,  Ray *ray, RTfloat k0,  RTfloat k1);
    Color getDiffuse();
    Color getSpecular();
    Color getAmbient();
    RTfloat getSpecularExp();
    void setAttributes(vector<double> a);
    bool isSpecular(); // return true if the surface is specular
    bool isDiffuse();  // return true if the surface is diffuse
};


#endif
