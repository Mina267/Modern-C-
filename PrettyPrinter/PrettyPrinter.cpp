#include <iostream>
#include <vector>
#include "PrettyPrinter.h"


void PrettyPrinter_Run(void)
{
	int data = 50;
	PrettyPrinter<int> p1(&data);
	p1.Print();

	float f = 5.52f;
	PrettyPrinter<float> p2(&f);
	p2.Print();

	char s[] = "Mina Magdy";
	PrettyPrinter<char*> p3(s);
	p3.Print();

	std::vector<int> v{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> p4(&v);
	p4.Print();
}



