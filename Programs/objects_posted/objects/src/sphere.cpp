/*
Author:  Herb Yang (based on a version by D. Neilson), March 9, 2010.
Purpose:
 Scene Object: Sphere
*/

#include <math.h>
#include "sphere.h"

// ========================================================================
//     getNormal of sphere
// ========================================================================

// Return the normal vector for the given point on the surface
Vector3 Sphere::getNormal(Vector3 *point) {
    Vector3 norm;
    norm = (*point) - center;
    norm.normalize();
    return norm;
} // getNormal
// ========================================================================
//     return true if the sphere is specular
// ========================================================================
bool Sphere::isSpecular()
{
    return( specular.r>0 || specular.g>0 || specular.b>0);
}
bool Sphere::isDiffuse()
{
    return( diffuse.r>0 || diffuse.g>0 || diffuse.b>0);
}

// ========================================================================
//    Sphere Intersection
// ========================================================================


// Find and return, in k, the earliest intersection point, in the
// range [k0,k1), along the given ray. Returns 1 if such a t exists,
// false otherwise
bool Sphere::intersect(RTfloat *k,  Ray *ray, RTfloat k0,  RTfloat k1)
{
    RTfloat A,B,C, discr, denom;
    RTfloat dist;
    Vector3 oc;
    oc = ray->o - center;
    A = (ray->d).length();
    A *= A;
    B = 2*( ray->d % oc);
    C = oc % oc - rad*rad;
    discr = B*B - 4*A*C;
    if(discr<0.0) return false;
    else
    {
        discr = sqrt(discr);
        denom = 1/(2*A);
        dist = (-B - discr)*denom;
        if ((dist > k0) && (dist < k1))
        {
            *k = dist;
            return true;
        }
        dist = (-B + discr)*denom;
        if ((dist > k0) && (dist < k1))
        {
            *k = dist;
            return true;
        }

    }
    return false;
} // intersect()
// getDiffuse() - return the diffuse coefficient
Color Sphere::getDiffuse() {
    return diffuse;
}
// getSpecular() - return the specular coefficient
Color Sphere::getSpecular() {
    return specular;
}
// getDiffuse() - return the ambient coefficient
Color Sphere::getAmbient() {
    return ambient;
}
// getSpecularExp() - return the Specular Exponent coefficient
RTfloat Sphere::getSpecularExp() {
    return specularExp;
}
// set the attributes of the sphere
// The order of the attributes is given below:
// rad: radius
// center.x
// center.y
// center.z
// diffuse.r
// diffuse.g
// diffuse.b
// ambient.r
// ambient.g
// ambient.b
// specular.r
// specular.g
// specular.b
// specularExp
void Sphere::setAttributes(vector<double> a) {
    rad = a[0];
    center.x = a[1];
    center.y = a[2];
    center.z = a[3];
    diffuse.r = a[4];
    diffuse.g = a[5];
    diffuse.b = a[6];
    ambient.r = a[7];
    ambient.g = a[8];
    ambient.b = a[9];
    specular.r = a[10];
    specular.g = a[11];
    specular.b = a[12];
    specularExp = a[13];
}
