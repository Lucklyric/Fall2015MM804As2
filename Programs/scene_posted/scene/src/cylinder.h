#ifndef CYLINDER_H
#define CYLINDER_H
/*
Author: Herb Yang, Oct. 2, 2010
*/

#include "mathtypes.h"
#include <algorithm>
#include "color.h"
#include "vector3.h"
#include "ray.h"
#include "geomObj.h"
#include <vector>
class Cylinder : public geomObj {// see the definition of geomObj for more explanation
public:
    RTfloat rad;    // the sphere's radius
    Vector3 c1, c2; // the two centers of the cylinder - the cylinder is open
    bool outside;   // a flag when set to true indicates the intersection is on the outside
    bool solidFlag; // set if it is a solid cylinder
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

#endif // CYLINDER_H
