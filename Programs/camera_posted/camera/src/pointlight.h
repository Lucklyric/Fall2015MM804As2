/*
Author: Herb Yang, March 9, 2010
*/

#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "color.h"
#include "mathtypes.h"
#include "vector3.h"

class PointLight {
public:
    Color col;			// color of the light
    Vector3 posn;			// position
};


#endif
