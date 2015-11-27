/*
Author:  Herb Yang, Oct. 23, 2015
Purpose:
Scene Object: Polygon
The polygon is specified by n vertices, p1, p2, ...
*/

#include <math.h>
#include "poly.h"
#include "vector3.h"
#include "plucker.h"


// ========================================================================
//     getNormal of polygon
// ========================================================================

// Return the normal vector for the given point on the surface
// The vertices are specified in CCW direction.
//
// point is here because to be consistent with other objects.
Vector3 Poly::getNormal(Vector3 *point) {


    return normal;// already computed when the attributes are set
} // getNormal
// ========================================================================
//     return true if specular
// ========================================================================
bool Poly::isSpecular()
{
    return( specular.r>0 || specular.g>0 || specular.b>0);
}
// ========================================================================
//     return true if diffuse
// ========================================================================
bool Poly::isDiffuse()
{
    return( diffuse.r>0 || diffuse.g>0 || diffuse.b>0);
}

// ========================================================================
//    Plucker test to check if the ray goes through the object
// ========================================================================
bool Poly::pluckerTest(Ray *ray){
	bool flag = true;
	// complete this function
	// Construct the plucker object
	Plucker rayP = Plucker(ray->d,ray->o);
	// Go through all the side of the poly
	for (int j = 0; j < nVertices; j++) {
		Vector3 p = this->vertices[j];
		Vector3 d;
		if (j == (nVertices - 1)) {
			// The last vertices
			d = this->vertices[0] - this->vertices[j];
		}
		else{
			d = this->vertices[j + 1] - this->vertices[j];
		}
		Plucker slideP = Plucker(d, p);
		// Check the inner product and determine the direction
		double value = rayP % slideP;
		if (value <= 0) {
			return false;
		}
	}
	return flag;
}

// Find and return, in k, the earliest intersection point, in the
// range [k0,k1), along the given ray. Returns 1 if such a k exists,
// false otherwise
bool Poly::intersect(RTfloat *k,  Ray *ray, RTfloat k0,  RTfloat k1)
{
	bool flag = false;
    // complete this function
	// First check if the ray inside the poly
	if (!pluckerTest(ray))
	{
		return false;
	}
	RTfloat t;
	Vector3 p;
	if ((ray->d % this->normal) >= 0)
	{
		return false;
	}
	// Calculate the t
	t = ((this->vertices[0] - ray->o) % this->normal) / (ray->d % this->normal);
	p = (ray->o - this->vertices[0]) + t*ray->d;
	// Check the interval
	if ((t > k0) && (t < k1))
	{
		*k = t;
		return true;
	}
	return flag;
} // intersect()
// getDiffuse() - return the diffuse coefficient
Color Poly::getDiffuse() {
    return diffuse;
}
// getSpecular() - return the specular coefficient
Color Poly::getSpecular() {
    return specular;
}
// getDiffuse() - return the ambient coefficient
Color Poly::getAmbient() {
    return ambient;
}
// getSpecularExp() - return the Specular Exponent coefficient
RTfloat Poly::getSpecularExp() {
    return specularExp;
}
// set the attributes of the polygon
// The order of the attributes is given below:
// nVertices
// vertices[0].x, vertices[0].y, vertices[0].z
// vertices[1].x, vertices[1].y, vertices[1].z
// ...
// vertices[nVertices-1].x, vertices[nVertices-1].y, vertices[nVertices-1].z
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
void Poly::setAttributes(vector<double> a) {
    int i = 0;
    nVertices =a[i++];
    vertices = new Vector3[nVertices];
    for(int j=0;j<nVertices;j++){
        vertices[j].x = a[i++];
        vertices[j].y = a[i++];
        vertices[j].z = a[i++];
    }
    diffuse.r = a[i++];
    diffuse.g = a[i++];
    diffuse.b = a[i++];
    ambient.r = a[i++];
    ambient.g = a[i++];
    ambient.b = a[i++];
    specular.r = a[i++];
    specular.g = a[i++];
    specular.b = a[i++];
    specularExp = a[i++];
    Vector3 aa = vertices[1]-vertices[0];
    Vector3 bb = vertices[nVertices-1]-vertices[0];
    normal = aa*bb; // cross product
    normal.normalize();
}
