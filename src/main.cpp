#include <iostream>
#include <cmath>
#include <math.h>
#include "../include/vectors.h"
#include "../include/matrix.h"
#include <iomanip>

int main(int argc, char **argv) {

	Vector a = vfc(std::sqrt(3),1);
	std::cout << a.magnitude << std::endl;
	Vector c = div_v(a,4096);
	std::cout << c.magnitude << std::endl;

	return 0;
	
}