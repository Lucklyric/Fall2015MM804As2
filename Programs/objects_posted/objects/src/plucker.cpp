/*
Author:  Herb Yang, Oct. 23, 2015
Purpose:
Define plucker coordinate
only the permutted inner product % is defined
*/
#include "plucker.h"
Plucker::Plucker(){
    d.x = d.y = d.z = 0.0;
    m.x = m.y = m.z = 0.0;
}

Plucker::Plucker(Vector3 a, Vector3 b){
    // complete this constructor

}
// compute the permutted inner product of two lines L1%L2
double Plucker::operator% (const Plucker& v) const{
	double a = 0.0;
   // complete this function
	return a;
}
