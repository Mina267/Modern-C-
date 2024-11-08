#include "iostream"
#include "string"
#include "unordered_set"

#include "Hash.h"

void Hash(void)
{
	std::unordered_set<Employee, EmployeeHash, EmpEquality> E;
	E.insert(Employee{ "Mina", 152 });
	E.insert(Employee{ "Magdy", 412 });
	E.insert(Employee{ "Aziz", 921 });
}





