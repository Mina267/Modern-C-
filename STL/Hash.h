#pragma once


class Employee
{
	std::string m_Name;
	int m_Id;
public:
	Employee(const std::string &n, int id) :m_Name(n), m_Id(id)
	{
	}
	const std::string& GetName() const
	{
		return m_Name;
	}

	int GetID() const
	{
		return m_Id;
	}
};

struct EmployeeHash
{
	size_t operator() (const Employee& emp) const
	{
		auto s1 = std::hash<std::string>{}(emp.GetName());
		auto s2 = std::hash<int>{}(emp.GetID());
		return s1 ^ s2;
	}
};

struct EmpEquality
{
	bool operator() (const Employee& emp1, const Employee& emp2) const
	{
		return emp1.GetID() == emp2.GetID() && emp1.GetName() == emp2.GetName();
	}
};

void Hash(void);