#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>


class Employee {
	std::string m_Name;
	int m_Id;
	std::string m_ProgLang;
public:
	Employee(const std::string& n, int id, const std::string& pl) :
		m_Name(n),
		m_Id(id),
		m_ProgLang(pl) {

	}
	const std::string& GetName()const {
		return m_Name;
	}
	int GetId()const {
		return m_Id;
	}
	const std::string& GetProgrammingLanguage()const {
		return m_ProgLang;
	}

	bool operator <(const Employee& e) const
	{
		return m_Id < e.m_Id;
	}
};

/* Function object  */
struct EmpIds
{
	std::vector<int> m_Ids;
	void operator()(const Employee& e)
	{
		if (e.GetProgrammingLanguage() == "C++")
		{
			/* adding this Id to membor function Vector */
			m_Ids.push_back(e.GetId());
		}
	}
};

void UserDefined() 
{
	std::vector<Employee> v{
		Employee{"Mina", 101, "C"},
		Employee{"Magdy", 251, "Java"},
		Employee{"Aziz", 200, "C++"}
	};

	//Use callback to avoid overloading comparison operators
	std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2)
		{
			return e1.GetName() < e2.GetName();
		});
	for (const auto& e : v) {
		std::cout
			<< "Id:" << e.GetId()
			<< " | Name:" << e.GetName()
			<< " | Language:" << e.GetProgrammingLanguage() << std::endl;
	}

	/* Count number of employees that now C++ */
	int Cnt{};
	for (const auto& x : v)
	{
		if (x.GetProgrammingLanguage() == "C++")
		{
			++Cnt;
		}
	}
	std::cout << "Count LOOP: " << Cnt << std::endl;



	//Terse, but gives more information to the reader as compared to a for loop
	Cnt = std::count_if(v.begin(), v.end(), [](const auto& e)
		{
			return e.GetProgrammingLanguage() == "C++";
		});
	std::cout << "Count Lambda: " << Cnt << std::endl;

	//Find if any employee knows Java
	
	auto itr = std::find_if(v.begin(), v.end(), [](const auto& e)
		{
			return e.GetProgrammingLanguage() == "Java";
		});
	if (itr != v.end())
	{
		std::cout << "Found: " << itr->GetName() << " is a Java programmer." << std::endl;
	}

	//Print all employee names
	std::for_each(v.begin(), v.end(), [](const auto &e)
		{
			std::cout << "Name: " << e.GetName() << std::endl;
		});

	//Get ids of all employees that know C++
	
	EmpIds Found_Ids = std::for_each(v.begin(), v.end(), EmpIds());
	for (auto i : Found_Ids.m_Ids)
	{
		std::cout << "Id: " << i << std::endl;
	}

}



//Custom comparator for associative containers
struct EmpCompare {
	bool operator ()(const Employee& e1, const Employee& e2)const {
		return e1.GetId() < e2.GetId();
	}
};
void SetAlg() {
	//Using custom comparator
	std::set<Employee, EmpCompare> v{
		//				 ^^^^
		Employee{"Mina", 101, "C"},
		Employee{"Magdy", 251, "Java"},
		Employee{"Aziz", 200, "C++"}
	};

	for (const auto& e : v) {
		std::cout
			<< "Id:" << e.GetId()
			<< " | Name:" << e.GetName()
			<< " | Language:" << e.GetProgrammingLanguage() << std::endl;
	}
}
