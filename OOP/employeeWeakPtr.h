#pragma once


class employee;




class project
{
public:
	std::shared_ptr<employee> m_emp;

	project()
	{
		std::cout << "Project()" << std::endl;
	}

	~project()
	{
		std::cout << "~Project()" << std::endl;

	}
};

class employee
{
public:
	/* weak to avoid memory leak happened cause circle of reference. */
	std::weak_ptr<project> m_prj;

	employee()
	{
		std::cout << "Employee()" << std::endl;

	}

	~employee()
	{
		std::cout << "~Employee()" << std::endl;

	}
};



void EmployeesWeak_Runnable(void);