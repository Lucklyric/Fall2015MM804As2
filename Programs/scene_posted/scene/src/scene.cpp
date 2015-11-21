/*
Author: Herb Yang March 9, 2010. Based on a version originally written by Daniel Neilson.
Updated: Oct. 11, 2015
*/
#include <iostream>
#include "scene.h"
#include "sphere.h"
#include "pointlight.h"
#include "geomObj.h"
extern Ray createRay(const Vector3 & to, const Vector3& from);
static unsigned depth;// to control recursion
// Black background
Color BACKGROUND(0.1,0.1,0.1);

void Scene::initScene()
{
    geomObj::list =0;
    lightList.clear();
    depth = 0;
}
// NOTHING TO TOUCH IN SHADE
// You need to read the code to understand some of the functions that you need to implement
void Scene::shade(Color *shading,  // shading is the return result
								   // Input:
	Ray *inc_ray,	// inc_ray - incoming ray
	Vector3 *point, // point - the point of intersection
	Vector3 *normal,// normal - normal at the point of intersection
	geomObj *objToLight, // objToLight - pointer to a list of lights
	Camera *cam)	// the camera
{
	RTfloat lightToNormal, dn;
	Ray ray, reflected_Ray;
	Color lightCol, indirectCol, tempC;
	int i;
	bool lit;
	lit = false;				// set the point not lit yet
	if (objToLight)// if not null
	{
		// added below - Nov. 12, 2015
		(*shading) += objToLight->getAmbient() * ambient_light;
		for (i = 0; i<(int)lightList.size(); i++)						// go through each light source
		{
			double t = rayToLight(&ray, point, &lightList[i]);	// ray is the return ray from the point of intersection to the light source, t is the distance
			lightCol = getPointLightColor(&ray, &lightList[i], t);// lightCol is equal to background is the light is blocked
			lightToNormal = ray.d % (*normal);					//cosine of the angle between the ray and the normal
			if (lightToNormal>0.0)
			{
				if (objToLight->isDiffuse())
				{
					lit = true;								// set the point lite
					tempC = (objToLight->getDiffuse()*lightCol);	// diffuse coefficient * light intensity
					tempC = tempC * lightToNormal;				// multiply by the cosine of the angle
					(*shading) += tempC; // add to shading
				}
				// specular
				if (objToLight->isSpecular())
				{
					// need to compute the reflected light direction
					// then compute the dot product between the reflected light and the viewer direction
					dn = cosViewerToReflectedRay(ray,// ray is the ray from the point of intersection to the light source
						*point,						 // point of intersection
						*normal,					 // normal at the point of intersection
						*cam);						 // the camera
					if (dn>0)
					{
						lit = true;
						dn = pow(dn, objToLight->getSpecularExp());// use Phong specular reflection model
						tempC = objToLight->getSpecular()*lightCol;
						tempC *= dn;				// multiply with dn
						(*shading) += tempC;		// add to shading
					}
				}

			} // end if (lightToNormal>0)
			  //else // in here, the point cannot recieve light
			  //{
			  //	if (!lit) // add ambient
			  //	{
			  //		(*shading) = objToLight->getAmbient() * ambient_light;
			  //	}
			  //}
		}

	}
	// recursion
	if (objToLight->isSpecular())
	{
		depth++;
		reflected_Ray = reflectedRay(*inc_ray, *point, *normal);	// compute reflected ray
		trace(&reflected_Ray, &indirectCol, cam);				// trace in the direction of the reflected ray
		(*shading) += indirectCol * objToLight->getSpecular();
		depth--;
	}
} // shade()
  //
  // create a ray from point to ptLight
  // return is the distance from point to ptLight
  //
double Scene::rayToLight(Ray *ray, Vector3 *point, PointLight *ptLight )
{
	// creates ray from point to point light ptLight.
	// Return includes a ray (ray) and the
	// distance from point to the point light
    double distance =0.0f;
	*ray = createRay(ptLight->posn, *point);
	distance = ray->distance(ptLight->posn);
    return distance;
}
// return the color of light if there is no obstructing object
// if there is obstruction, then the returned color is black
// ray - normalized unit towards ptLight
// ptLight - pointer to a pointlight source
// distance - distance to the light source
// the idea is to check if there is an intersection of objects in between 0 and 1
// 0 is at the point of intersection and 1 is at the light source
Color Scene::getPointLightColor(Ray *ray, PointLight *ptLight, double distance)// distance is the distance to the source
{
    Color col;
    col = Color(0.,0.,0.);
    // complete this function
	bool ifOb = false;
	geomObj* tmpObj = geomObj::list;
	while (tmpObj != 0)
	{
		RTfloat check;
		if (tmpObj->intersect(&check, ray, F_EPSILON, F_INFINITY)) {
			if (F_GT(check,0) && F_LT(check , distance))
			{
				ifOb = true;
				break;
			}
		}
		tmpObj = tmpObj->next;
	}
	if (!ifOb)
	{
		col = ptLight->col;
	}
    return(col);
}
void Scene::trace(Ray * ray, Color *col, Camera *cam)
{
    RTfloat t, minT,  dist;
    Vector3 point;
    Vector3 normal;
    // initialize col to background
    (*col) = BACKGROUND;
    if(depth>MAXDEPTH) return;
    minT = F_INFINITY;
    geomObj *obj=findFirstIntersection(ray, &dist, F_EPSILON, F_INFINITY);
    // something intersect the ray at dist
    // compute the coordinates of the intersection
    if(obj) // if there is a hit
    {
        point = ray->o;
        point += ray->d * dist;
        normal = obj->getNormal(&point); // get the normal
        t = normal % ray->d;	// check if the normal is in the direction of the ray
        if(t<0.0)
            shade(col,ray,&point,&normal,obj, cam);	// shade the point
    }
}
//  Find the first intersection of ray with an object in the scene in the
// interval [k0,k1).
// Returns 0 if no such object is found
// The intersection point is: ray.o + k * ray.d
geomObj* Scene::findFirstIntersection( Ray *ray, RTfloat *k,
                                       RTfloat k0, RTfloat k1) {
    geomObj * hitObj = 0;
    // complete this function
	geomObj* tmpObj = geomObj::list;
	RTfloat minK = k1;
	while (tmpObj != 0)
	{
		RTfloat check;
		if (tmpObj->intersect(&check, ray, k0, k1)) {
			if (F_LT(check , minK))
			{
				hitObj = tmpObj;
				minK = check;
			}
		}
		tmpObj = tmpObj->next;
	}
	*k = minK;
    return hitObj;
} // findFirstIntersection()
Ray Scene::reflectedRay(Ray inc_ray,// incoming ray
                        Vector3 point,				// point of intersection
                        Vector3 normal)				// normal
{
    Ray rRay;
   // complete this function
	Vector3 reflectedVector = inc_ray.reflectedDirection(normal);
	rRay = createRay(point + reflectedVector, point);
    return rRay;
} // reflected Ray
double Scene::cosViewerToReflectedRay( // returns the cosine of the angle between the viewer and the reflected ray
        Ray ray,				// the ray to the light sourse from the point of intersection
        Vector3 point,			// the point of intersection
        Vector3 normal,			// normal at the point of intersection
        Camera cam)				// the camera, i.e. viewer
{
    Vector3 directionToViewer, tempV, reflectedLightVector;
    double dn =0.0f;
    // complete this function
	reflectedLightVector = -(reflectedRay(ray, point, normal).d);
	directionToViewer = (cam.eye - point);
	directionToViewer.normalize();
	dn = ((reflectedLightVector.dot(directionToViewer)) / (reflectedLightVector.length()*directionToViewer.length()));
    return dn;
}
