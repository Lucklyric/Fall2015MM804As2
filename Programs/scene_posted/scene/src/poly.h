/*
Author:  Herb Yang, July 30, 2011
Purpose:
Scene Object: Polygon
The polygon is specified by n vertices, p1, p2, ...
*/
#ifndef POLY_H
#define POLY_H
#include "mathtypes.h"
#include "color.h"
#include "vector3.h"
#include "ray.h"
#include "geomObj.h"
#include "plucker.h"
#include <vector>
class Poly : public geomObj
{
public:
    Vector3 normal;                     // the normal
    int nVertices;                      // number of vertices
    Vector3 *vertices;                  //  vertices
    Color diffuse, ambient, specular;
    RTfloat specularExp;
    Vector3 getNormal(Vector3 *point);// Return the normal vector for the given point on the surface
    //  Find and return, in k, the earliest intersection point, in the
    //  range [k0,k1), along the given ray. Returns 1 if such a t exists,
    //  false otherwise
    bool intersect(RTfloat *k,  Ray *ray, RTfloat k0,  RTfloat k1);
    Color getDiffuse();
    Color getSpecular();
    Color getAmbient();
    RTfloat getSpecularExp();
    void setAttributes(vector<double> a);
    bool pluckerTest(Ray *ray); // to test if ray goes through the triangle - true = yes
    bool isSpecular();          // return true if the surface is specular
    bool isDiffuse();           // return true if the surface is diffuse
};
#endif // POLY_H
