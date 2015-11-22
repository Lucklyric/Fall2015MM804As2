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
	Vector3 A = (*point) - this->c1;
	Vector3 cc = this->c2 - this->c1;
	Vector3 cdp = A.dot(cc) / (cc.length())*(cc/cc.length());
	norm = A - cdp;
	norm.normalize();
	if (!outside) {
		norm *= -1;
	}
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
	Vector3 cc = this->c2 - this->c1;
	Vector3 l = cc / (cc.length());
	Vector3 A = ray->o - this->c1;
	Vector3 B = ray->d - (ray->d % l)*l;
	Vector3 C = -(ray->o % l - this->c1 % l)*l;
	Vector3 AC = A + C;
	// (A+t(B)+C) % (A+t(B)+C) = r^2;
	// (AC.x + tB.x)^2 + (AC.y + tB.y)^2 + (AC.z + tB.z)^2 = r^2;
	// (AC.x)^2 + (AC.y)^2 + (AC.z)^2 - r^2 = Val1;
	// 2(AC.x*B.x + AC.y*B.y + AC.z * B.z) = Val2;
	// (B.x)^2 + (B.y)^2 + (B.z)^2 = Val3;
	// t^2*Val3 + t*val2 + val1 = 0;
	// discr = val2^2 - 4*val1*val3;
	// t = (- val2 +- sqrt(discrt))/2*val3;
	RTfloat val1, val2, val3, discr,denom,dist1,dist2,t1,t2;
	val1 = pow(AC.x, 2) + pow(AC.y, 2) + pow(AC.z, 2) - pow(this->rad, 2);
	val2 = 2*(AC.x * B.x + AC.y * B.y + AC.z * B.z);
	val3 = pow(B.x, 2) + pow(B.y, 2) + pow(B.z, 2);
	discr = pow(val2, 2) - 4 * val1*val3;
	if (F_LT(discr , 0.0)) return false;
	else {
		discr = sqrt(discr);
		denom = 1 / (2 * val3);
		dist2 = (-val2 + discr) * denom;
		dist1 = (-val2 - discr) * denom;
		t2 = MAX(dist2, dist1);
		t1 = MIN(dist2, dist1);

		if (fabs(t1) < MIN_OBJ_DIST)
		{
			RTfloat m = ray->o % l + (t1*ray->d)%l - this->c1 % l;
			if (m>= 0 & m <=(cc.length()))
			{
				*k = t1;
				outside = false;
				return true;
			}
		}
		if ((t1 > k0)&& (t1< k1)) {
			RTfloat m = ray->o % l + (t1*ray->d) % l - this->c1 % l;
			if (m >= 0 & m <= (cc.length()))
			{
				*k = t1;
				outside = true;
				return true;
			}
		}
		if (!solidFlag) {
			if ((t2 > k0) && (t2< k1)) {
				RTfloat m = ray->o % l + (t2*ray->d) % l - this->c1 % l;
				if (m >= 0 & m <= (cc.length()))
				{
					*k = t2;
					outside = false;
					return true;
				}
			}
		}
	}
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

