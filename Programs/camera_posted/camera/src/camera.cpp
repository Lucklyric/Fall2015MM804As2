/*
Author: Herb Yang, March 9, 2010 - modified based on a version by Daniel Neilson
*/

#include "camera.h"

Camera::Camera(){}

// Initialize the camera. Return 1 iff successful
Camera::Camera(			// constructor
        Vector3 _up,  Vector3 _gaze,  Vector3 _eye,
        RTfloat _viewDist,
        RTfloat _ruX,  RTfloat _ruY,
        RTfloat _llX,  RTfloat _llY,
        screen_res_t _X,  screen_res_t _Y) {

    eye = _eye;
    up = _up;
    gaze = _gaze;
    s = _viewDist;
    bu = _ruX;
    bv = _ruY;
    au = _llX;
    av = _llY;
    Nx = _X;
    Ny = _Y;
    createONB(gaze, up);// create the OMB basis vectors
}
// Initialize the camera. Return 1 iff successful
int Camera::initCamera(
        Vector3 _up,  Vector3 _gaze,  Vector3 _eye,
        RTfloat _viewDist,
        RTfloat _ruX,  RTfloat _ruY,
        RTfloat _llX,  RTfloat _llY,
        screen_res_t _X,  screen_res_t _Y) {
    eye = _eye;
    up = _up;
    gaze = _gaze;
    s = _viewDist;
    bu = _ruX;
    bv = _ruY;
    au = _llX;
    av = _llY;
    Nx = _X;
    Ny = _Y;
    createONB(gaze,up);// create the ONB basis vectors
    //first_time = true; // for random sampling
    return 1;
}
// Create and return a ray through the desired pixel - the ray direction is normalized. The origin of the
// ray is at the center of the camera or the eye location
Ray Camera::getRayThroughPixel( screen_res_t x, screen_res_t y)  {
    Ray ray;		// the ray we're returning
    Vector3 pos;	// the pixel location in UVW coordinate
    ray.o = eye;
    int tempx, tempy;
    float tempfx, tempfy;
    tempx = (int) rand();
    tempfx = float(tempx %RANGE);
    tempy = (int) rand();

    tempfy = float(tempy % RANGE);// temp x and temp y are in the range of 0 to RANGE

    tempfx = tempfx/RANGE;
    tempfy = tempfy/RANGE;

    pos.x = au + (bu -au)*(x+tempfx)/(Nx-1);
    pos.y = av + (bv -av)*(y+tempfy)/(Ny-1);
    pos.z = -s;

    // Convert the uvw coordinates into xyz coordinates, and place the result
    // in the ray
    ray.d = fromCameraToWorld(pos);
    ray.d  = ray.d - ray.o;
    ray.d.normalize();
    return ray;
} // getRayThroughPixel
void Camera::createONB(const Vector3& a, const Vector3& b)
{

   // add code to this function
	
}
// transform from the camera coordinate system to the world coordinate system
Vector3 Camera::fromCameraToWorld(Vector3 & p)
{
	Vector3 a; 
    // add code to this function
	
	return a;
}

