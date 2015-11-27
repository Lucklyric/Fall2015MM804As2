/*
Author: Herb Yang, March 9, 2010
*/

#ifndef GEOMOBJ_H
#define GEOMOBJ_H

#include "mathtypes.h"
#include "color.h"
#include "vector3.h"
#include "ray.h"
#include <vector>
using namespace std;
class geomObj {
public:
    static geomObj * list;                                              // a list of object
    geomObj * next;
    // pointer to the next object
    geomObj() { next = list; list = this;} // constructor
    virtual Vector3 getNormal(Vector3 *point)=0;// Return the normal vector for the given point on the surface
    // Find and return, in k, the earliest intersection point, in the
    // range [k0,k1), along the given ray. Returns 1 if such a t exists,
    // false otherwise
    virtual bool intersect(RTfloat *k,  Ray *ray, RTfloat k0,  RTfloat k1)=0;// see above
    virtual Color getDiffuse()=0;	// get diffuse property
    virtual Color getSpecular()=0;// get specular property
    virtual Color getAmbient()=0; // get ambient property
    virtual RTfloat getSpecularExp()=0;// get the exponent in phong model
    virtual void setAttributes(vector<double> a)=0;// set all the attributes for the object
    virtual bool isSpecular()=0; // return true if the surface is specular
    virtual bool isDiffuse()=0;  // return true if the surface is diffuse
};


#endif


