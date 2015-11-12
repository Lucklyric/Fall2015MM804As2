/*
Author:  Herb Yang, Oct. 2, 2010.

Scene Object: Disk
*/

#include <math.h>
#include "disk.h"

// ========================================================================
//     getNormal of sphere
// ========================================================================

// Return the normal vector for the given point on the surface
Vector3 Disk::getNormal(Vector3 *point) {
    return normal;
} // getNormal
// ========================================================================
//     return true if the sphere is specular
// ========================================================================
bool Disk::isSpecular()
{
    return( specular.r>0 || specular.g>0 || specular.b>0);
}
bool Disk::isDiffuse()
{
    return( diffuse.r>0 || diffuse.g>0 || diffuse.b>0);
}



// Find and return, in k, the earliest intersection point, in the
// range [k0,k1), along the given ray. Returns 1 if such a k exists,
// false otherwise
bool Disk::intersect(RTfloat *k,  Ray *ray, RTfloat k0,  RTfloat k1)
{
	bool flag = false; // intersection flag
	// complete this function


    return flag;
} // intersect()
// getDiffuse() - return the diffuse coefficient
Color Disk::getDiffuse() {
    return diffuse;
}
// getSpecular() - return the specular coefficient
Color Disk::getSpecular() {
    return specular;
}
// getDiffuse() - return the ambient coefficient
Color Disk::getAmbient() {
    return ambient;
}
// getSpecularExp() - return the Specular Exponent coefficient
RTfloat Disk::getSpecularExp() {
    return specularExp;
}
// set the attributes of the sphere
// The order of the attributes is given below:
// rad: radius
// center.x
// center.y
// center.z
// normal.x
// normal.y
// normal.z
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
void Disk::setAttributes(vector<double> a) {
    rad = a[0];
    center.x = a[1];
    center.y = a[2];
    center.z = a[3];
    normal.x = a[4];
    normal.y = a[5];
    normal.z = a[6];
    normal.normalize();
    diffuse.r = a[7];
    diffuse.g = a[8];
    diffuse.b = a[9];
    ambient.r = a[10];
    ambient.g = a[11];
    ambient.b = a[12];
    specular.r = a[13];
    specular.g = a[14];
    specular.b = a[15];
    specularExp = a[16];
}
