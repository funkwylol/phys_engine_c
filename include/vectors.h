#pragma once
#include <cmath>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>


// Converting degrees to radians for the math library functions
double Convert(double degrees, double radians, int d) {
	// Switch for d variable
	switch (d) {
		case 1:
			radians = (degrees * (3.14159265359/180));
			return radians;
			break;
		case 2:
			degrees = radians/(3.14159265359/180);
			return degrees;
	}
}

// Pythagorean theorem
float pythag(float a,float b,float c,int d) {
	if (d==0) {
		float a=std::sqrt(std::pow(c,2)-std::pow(b,2));
		return a;
	}
	else if (d==1) {
		float b=std::sqrt(std::pow(c,2)-std::pow(a,2));
		return b;
	}
	else if (d==2) {
		float c=std::sqrt(std::pow(a,2)+std::pow(b,2));
		return c;
	}
}

// Pythagorean theorem but 3d
float pythag_3d(float x, float y, float z, float c, int d) {
	if (d==0) {
		x=std::sqrt(std::pow(c,2)-std::pow(z,2)-std::pow(y,2));
		return x;
	}
	else if (d==1) {
		y=std::sqrt(std::pow(c,2)-std::pow(y,2)-std::pow(z,2));
		return y;
	}
	else if (d==2) {
		z=std::sqrt(std::pow(c,2)-std::pow(y,2)-std::pow(x,2));
		return z;
	}
	else if (d==3) {
		c=std::sqrt(std::pow(x,2)+std::pow(y,2)+std::pow(z,2));
		return c;
	}

}

// Vector class to create vector objects with magnitude and angle. 
// These probably already exist and probably come with C++ but its faster to just make it myself and I acually understand how tf it works.
class Vector {
	public:
	// Magnitude
		float magnitude;
	// Angle (Direction)
		float angle;
};
// 3d vector
class Vector_3d {
	public:
		float magnitude;
		// 2 angles, angle alpha and angle beta, since its in 3d.
		float angle1;
		float angle2;
		// If both angles equal zero, then it is pointing in the +x direction.
		// Angle alpha (1), is measured in degrees from the x axis, angle beta(2) is measured from the y axis.
		
};

// Takes in vector, returns vector (Dynamic array) with x and y components
std::vector<float> v_comps(Vector v) {
	float ra = Convert(v.angle,0,2);
	float vx = v.magnitude * std::cos(ra);
	float vy = v.magnitude * std::sin(ra);
	std::vector<float> comps = {vx,vy};
	return comps;
}

// 3d version of v_comps, same thing, but in 3d.
std::vector<float> v_comps_3d(Vector_3d v) {
	float ra1 = Convert(v.angle1,0,2);
	float ra2 = Convert(v.angle2,0,2);
	float vx = v.magnitude * std::cos(ra1);
	float vy = v.magnitude * std::sin(ra1);
	float vz = v.magnitude * std::sin(ra2);
	std::vector<float> comps_3d = {vx, vy, vz};
	return comps_3d;
}

// Takes in x and y components of vector, returns a Vector with the same magnitude and direction. 

// Function type is of vector because it returns a vector
Vector vfc(float x, float y) {
	// Uses pythagorean theorem to solve for magnitude (c)
	float c = pythag(x,y,0,2);
	// Uses inverse tan or arctan to solve for angle of vector.
	float a1 = std::atan(y/x);
	float a = Convert(0,a1,1);
	Vector v1;
	v1.magnitude = c;
	v1.angle = a;
	return v1;
}

// same as vfc(), but in 3d, 
Vector_3d vfc_3d(float x, float y, float z) {
	float c = pythag_3d(x,y,z,0,3);
	// Solving for angle 1 and 2, y acts to z just the same as x acts to y, so y can be measured as both the cos(a2) or the sin(a1)
	float a11 = std::atan(y/x);
	float a21 = std::atan(z/y);
	float a1 = Convert(0,a11,2);
	float a2 = Convert(0,a21,2);
	Vector_3d v1;
	v1.magnitude = c;
	v1.angle1 = a1;
	v1.angle2 = a2;
	return v1;
}

// Takes the sum of two vectors, va, vb, and outputs a vector c with that value.
Vector sum_v(Vector a, Vector b) {
	// Creates dynamic array for the components of vector a and b
	std::vector<float> comps_a = v_comps(a);
	std::vector<float> comps_b = v_comps(b);
	// Adds the components to make the new vector
	float ax = comps_a[0];
	float ay = comps_a[1];
	float bx = comps_b[0];
	float by = comps_b[1];
	float cx = ax + bx;
	float cy = ay + by;
	// Create the new vector
	Vector c = vfc(cx,cy);
	return c;
}

// Vector subtraction, same as adddition but instead of summning the components, it subtracts them.
Vector sub_v(Vector a, Vector b) {
	std::vector<float> comps_a = v_comps(a);
	std::vector<float> comps_b = v_comps(b);
	float ax = comps_a[0];
	float ay = comps_a[1];
	float bx = comps_b[0];
	float by = comps_b[1];
	float cx = ax - bx;
	float cy = ay - by;
	Vector c = vfc(cx,cy);
	return c;
}

// Multiplying vectors, same as addition but it adds to itself, so 2a. And so, ax + ax can just be represented as 2ax, which means you can do the same as the addition, but instead of adding the components, you multiply them by the scalar.
Vector mult_v(Vector a, float b) {
	std::vector<float> comps_a = v_comps(a);
	float ax = comps_a[0];
	float ay = comps_a[1];
	float cx = ax * b;
	float cy = ay * b;
	Vector c = vfc(cx,cy);
	
	// Had i done what i wanted to before, which was to make a recursive function that adds to the previous value by an amount of the vector. It kept 

	return c;
}

// Division is the same as multiplying by 1 over that number, so we just use the multiplication function.
Vector div_v(Vector a, float b) {
	return mult_v(a,(1/b));
}