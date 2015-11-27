//Author: Herb Yang, March 9, 2010
#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
    double x,y,z;
    // constructor
    Vector3();
    Vector3(const double x,const double y,const double z);
    Vector3(const Vector3& v);
    // assignment operator
    Vector3& operator=(const Vector3& a);
    // set the value of the 3 components - Usage: a.setValue(x,y,z);
    void setValue(const double& x,const double& y,const double& z);

    // cross product - Usage: c = a.cross(b); both a and b are not changed
    Vector3 cross(const Vector3 & b) const;

    // dot product - Usage: c = a.dot(b); both a and b are not changed.
    double dot(const Vector3 & b);

    // scale - Usage: p.scale(a); each component of p is multiplied by a.
    void scale(const double &factor);

    // normalization - Usage: a.normalize(); normalize the vector to a unit vector
    void normalize();

    // norm  of a vector
    double norm() const;
    double length() const;
    //
    // * and *= for double
    Vector3& operator*=(const double &a);
    Vector3 operator* (const double& a) const;
    friend Vector3 operator* (const double& a, const Vector3& v);
    //
    // / and /= for double divide by a double
    //
    Vector3& operator/=(const double &a);
    Vector3 operator/ (const double& a) const;
    //
    // overloaded operator: cross product
    //
    Vector3& operator*=(const Vector3& v2);
    Vector3 operator* (const Vector3& v2) const;
    //
    // overloaded operator: dot product
    //
    double operator% (const Vector3& v) const;
    //
    // operator += and +
    //
    Vector3& operator+=(const Vector3 &a);
    Vector3 operator+(const Vector3& v) const;
    //
    // operator -= and -
    //
    Vector3& operator-=(const Vector3 &a);
    Vector3 operator-(const Vector3 &v) const;
    // negation v = -p
    Vector3 operator-() const;


};

#endif //VECTOR3_H
