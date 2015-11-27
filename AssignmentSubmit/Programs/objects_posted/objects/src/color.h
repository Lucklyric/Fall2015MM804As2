/*
Author: Herb Yang, March 9, 2010

Purpose:
  Definition of the color class. This class represents color and its member functions.
*/

#ifndef COLOR_H
#define COLOR_H
#include "mathtypes.h"

class Color {
public:
    double r, g, b; // red, green, blue, the value of each channel is between 0 and 1.
    // constructors
    Color();
    Color(double r,double g,double b);
    Color(const Color& c);
    // set the value of the 3 components
    void setValue(double r,double g,double b);
    void setColor(const Color& c);	// set the color to c
    void setZero();					// set the color to (0.,0.,0.)
    Color& operator+=(const Color &c);
    Color& operator+=(const double &a);
    Color& operator*=(const Color &c);
    Color& operator*=(const double&a);
    Color& operator*=( double&a);
    void multValue(double factor);	// multiply color with factor
    void multColor(Color a);		// multiply each channel of color with each channel of a
    void clamp();					// if the value of channel is larger than 1, then return 1 for that channel
    friend Color operator*(const Color& a, const Color &b);// all operations are channel by channel
    friend Color operator+(const Color& a, const Color &b);
    friend Color operator*(const Color& a, const double&b);
    friend Color operator*(const double& b, const Color &a);
    friend Color operator/(const Color& a, const double &b);
};

#endif

