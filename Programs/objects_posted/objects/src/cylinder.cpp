/*
Author: Herb Yang, Oct. 23, 2015
		
Scene Object: Cylinder
*/

#include <math.h>
#include "cylinder.h"
#include <stdio.h>

// ========================================================================
//     getNormal of cylinder
// ========================================================================

// Return the normal vector for the given point on the surface
Vector3 Cylinder::getNormal(Vector3 *point) {
    Vector3 norm;//  normal of the cylinder
    // complete this function
	// ...

    return norm;
} // getNormal
// ========================================================================
//     return true if the cylinder is specular
// ========================================================================
bool Cylinder::isSpecular()
{
    return( specular.r>0 || specular.g>0 || specular.b>0);
}
bool Cylinder::isDiffuse()
{
    return( diffuse.r>0 || diffuse.g>0 || diffuse.b>0);
}

// ========================================================================
//    Cylidner Intersection
// ========================================================================


// Find and return, in k, the earliest intersection point, in the
// range [k0,k1), along the given ray. Returns 1 if such a k exists,
// false otherwise
bool Cylinder::intersect(RTfloat *k,  Ray *ray, RTfloat k0,  RTfloat k1)
{
	bool flag = false; // intersection flag
	// complete this function

    return flag;
} // intersect()
// getDiffuse() - return the diffuse coefficient
Color Cylinder::getDiffuse() {
    return diffuse;
}
// getSpecular() - return the specular coefficient
Color Cylinder::getSpecular() {
    return specular;
}
// getDiffuse() - return the ambient coefficient
Color Cylinder::getAmbient() {
    return ambient;
}
// getSpecularExp() - return the Specular Exponent coefficient
RTfloat Cylinder::getSpecularExp() {
    return specularExp;
}
// set the attributes of the cylinder
// The order of the attributes is given below:
// rad: radius
// center1.x
// center1.y
// center1.z
// center2.x
// center2.y
// center2.z
// solidFlag
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
void Cylinder::setAttributes(vector<double> a) {
    rad         = a[0];
    c1.x        = a[1];
    c1.y        = a[2];
    c1.z        = a[3];
    c2.x        = a[4];
    c2.y        = a[5];
    c2.z        = a[6];
    solidFlag   = a[7];
    diffuse.r   = a[8];
    diffuse.g   = a[9];
    diffuse.b   = a[10];
    ambient.r   = a[11];
    ambient.g   = a[11];
    ambient.b   = a[12];
    specular.r  = a[14];
    specular.g  = a[15];
    specular.b  = a[16];
    specularExp = a[17];
}

