
#include <iostream>
#include "math.h"
#include "Car.h"
#include "Integer.h"
#include "App1.h"
#include "employees.h"
#include "Printer.h"
#include "employeeWeakPtr.h"


using namespace std;


Integer Add1(const Integer& a, const Integer& b) {
	Integer temp;
	temp.SetValue(a.GetValue() + b.GetValue());
	return temp;
}

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int main()
{

	//Integer i1(5);
	//Integer i2(i1);
	//std::cout << "&i1:   " << &i1 << std::endl << std::endl;
	

	//Integer a(1), b(3);
	//Integer sum = a + b;
	//std::cout << "sum =  " << sum.GetValue() << std::endl;

	//Operate(5);

	//Printer_Runnable();

	//EmployeesWeak_Runnable();

	// [2][5]
	//int* p = new int[10] {1, 2, 3, 4, 5, 10, 20, 30, 40, 50};
	//int(*a)[5] = reinterpret_cast<int(*)[5]>(p);

	//int(*matrix)[5] = new int[2][5]{ {1, 2, 3, 4, 5}, {10, 20, 30, 40, 50} };
	
	//std::cout << matrix[1][2] << "   " << a[1][2] << std::endl;

	//Printer_Runnable();

	/*
	std::string csvLine = "123,45.67,hello world";
	std::stringstream ss(csvLine);


	std::vector<std::string> parsedData;
	std::string item;

	while (std::getline(ss, item, ',')) {
		parsedData.push_back(item);
	}

	for (const auto& field : parsedData) {
		std::cout << field << std::endl;
	}
	*/

	Integer x(5);

	x++ = 20;

	std::cout << x.GetValue() << std::endl;

	while (1)
	{

	}

	return 0;
}


