#pragma once

#include <iostream>
#include <string>

#include "Integer.h"

class Employee
{
	const std::string m_Name;
	Integer m_ID;
public:
	/* Even if we initialize these member variables with temporary in the main,
	 * it will perform copying, not moving. */
	Employee(const std::string &name, const Integer &id): m_Name{ name }, m_ID{ id }
	{
		std::cout << "Employee(const std::string &name, const Integer &id" << std::endl;
	}

	/* Make another constructor take the R value to use copy semantics for a temporary object.. */
	Employee(std::string&& name, Integer&& id) : m_Name{ std::move(name) }, m_ID{ std::move(id) }
	{
		std::cout << "Employee(std::string &&name, Integer &&id" << std::endl;
	}


	template<typename T1, typename T2>
	Employee(T1&& name, T2&& id) : 
		/* By using std::forward<T1>(name) and std::forward<T2>(id), 
		 * perfect forwarding is achieved, ensuring that the type of the arguments is maintained during forwarding, 
		 * whether they are L-value references or R-value references. 
		 */
		m_Name{ std::forward<T1>(name) }, 
		m_ID{ std::forward<T1>(id) }
	{
		std::cout << "Employee(NameType&& name, IdType&& id)" << std::endl;
	}



	~Employee()
	{
	}

private:

};



