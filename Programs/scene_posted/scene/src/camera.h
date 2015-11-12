//
// Author: Herb Yang, March 9, 2010
//
#ifndef CAMERA_H
#define CAMERA_H
#include "mathtypes.h"
#include "vector3.h"
#include "ray.h"
#include "onb.h"
#include <stdlib.h>
#include <time.h>
// The screen resolution is defined as type screen_res_t
typedef unsigned short screen_res_t;
#define RANGE 10000


class Camera {
public:
    Vector3 eye,		// eye is the location of the camera
    up,			// up is the up vector
    gaze;			// gaze is the direction of the camera
    ONB basis;		// basis is the orthonormal basis
    RTfloat s;		// s is the distance of the image plane from the centre of projection
    RTfloat au,av,	// a(u,v) are the lower left corner of the image plane
    bu,bv;		// b(u,v) are the upper right corner of the image plane (see lecture notes)
    screen_res_t Nx, Ny;// Nx, Ny, are the number of pixels in the x and y direction of the image plane
    Camera(); // default constructor
    Camera(
            Vector3 up,  Vector3 gaze,  Vector3 eye,
            RTfloat viewDist,
            RTfloat ruX,  RTfloat ruY,// ruX, ruY are the coordinates of the upper right corner of the image plane
            RTfloat llX,  RTfloat llY,// llX, llY are the coordinates of the lower left corner of the image image
            screen_res_t X,  screen_res_t Y);
    int initCamera(
            Vector3 up,  Vector3 gaze,  Vector3 eye,
            RTfloat viewDist,
            RTfloat ruX,  RTfloat ruY,
            RTfloat llX,  RTfloat llY,
            screen_res_t X,  screen_res_t Y);
    Ray getRayThroughPixel( screen_res_t x, screen_res_t y);// create a ray through a pixel at (x,y)
    void createONB(const Vector3 &a , const Vector3& b);    // create an Orthonormal Basis system from a and b
    Vector3 fromCameraToWorld(Vector3& pos);				  // given the location the camera coordinate system, return the coordinates
    // in the world coordinate system

};

#endif
