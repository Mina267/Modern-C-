#include <iostream>
#include "SmartPointer.h"
int SM_run() {
	int data = 800;
	SmartPointer<int[]> s1{ new int[5] };
	s1[0] = 5;
	std::cout << s1[0] << std::endl;
	return 0;
}