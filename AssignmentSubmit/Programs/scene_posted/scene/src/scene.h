/*
Author: Herb Yang, March 9, 2010
*/

#ifndef SCENE_H
#define SCENE_H
#include "color.h"
//#include "sphere.h"
#include "pointlight.h"
#include "camera.h"
#include "ray.h"
#include "geomObj.h"
#include <vector>
#define MAXDEPTH 10 // define the maximum recursion level
using namespace std;

class Scene {
public:
    vector<PointLight> lightList;	// a list of lights
    Color ambient_light;			// color of the ambient light
    void initScene();				// initialize the scene
    void shade(Color *shading,    // shading is the return color
               Ray *inc_ray,				// inc_ray - incoming ray
               Vector3 *point,			// point of intersection
               Vector3 *normal,			// normal at the point of intersection
               geomObj *objToLight,		// pointer to a list of objects to light
               Camera *cam);				// camera
    geomObj* findFirstIntersection( // returns the first object that intersects the ray
            Ray *ray,					// the ray
            RTfloat *k,				// the value of k at the intersection
            RTfloat k0,				// the minimum k allowed
            RTfloat k1);				// the maximum k allowed
    Color getPointLightColor(		// returns the color of the light
            Ray *ray,					// the ray
            PointLight *ptLight,		// the point light
            double distance);			// distance in parametric value of the point of intersection to the light source
    // this value is returned by rayToLight (see below)
    double rayToLight(			// returns the distance from point of intersection to the light source
            Ray *ray,					// returns the ray from the point of intersection to the light source
            Vector3 *point,			// input : point of interection of the ray
            PointLight *ptLight);		// input : pointlight
    Ray reflectedRay(Ray inc_ray,// incoming ray
                     Vector3 point,			// point of intersection
                     Vector3 normal);			// normal
    double cosViewerToReflectedRay( // returns the cosine of the angle between the viewer and the reflected ray
            Ray ray,				// the ray to the light sourse from the point of intersection
            Vector3 point,			// the point of intersection
            Vector3 normal,			// normal at the point of intersection
            Camera cam);			// the camera, i.e. viewer
    void trace(Ray *ray,			// the ray
               Color *col,				// returns the color
               Camera *cam);				// camera
};


#endif
