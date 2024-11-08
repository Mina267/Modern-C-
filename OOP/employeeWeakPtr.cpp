#include "iostream"
#include <string>
#include "employeeWeakPtr.h"
void EmployeesWeak_Runnable(void)
{
	std::shared_ptr<employee> emp{ new employee{} };
	std::shared_ptr<project> prj{ new project{} };
	
	/* the Distractor of the objects are not invoked, this indicates the memory is not released
	 * and leads memory leak
	 * This condition is called a circle of reference.
	 * This means there are two objects and both objects point to each other.
	 * So make one of class weak pointer
	 */

	/* Weak Smart pointer */emp->m_prj = prj; /* The shared smart pointer will not increment the reference counter. */
	prj->m_emp = emp;

}








