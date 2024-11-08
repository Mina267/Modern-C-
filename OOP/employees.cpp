#include "iostream"
#include <string>
#include "Employees.h"






/*************** With smart pointers ************/


static void ShowInfo(const std::shared_ptr<Employee>& emp);

void Employees_Runnable(void)
{
	/* Now we are able to share the project smart pointer with other objects.
	 * that unique pointer can not do
	 */ 
	std::shared_ptr<Project> prj{ new Project{} };
	prj->SetName("Video Decoder");
	std::shared_ptr<Employee> e1{ new Employee{} };
	e1->SetProject(prj);
	std::shared_ptr<Employee> e2{ new Employee{} };
	e2->SetProject(prj);
	std::shared_ptr<Employee> e3{ new Employee{} };
	e3->SetProject(prj);

	ShowInfo(e1);
	ShowInfo(e2);


	std::cout << "Reference count : " << prj.use_count() << '\n';

	prj->ShowProjectDetails();

	

}
/* To avoid copy of ptr pass emp variable by reference */
static void ShowInfo(const std::shared_ptr<Employee>& emp)
{
	std::cout << "Employee project details: ";
	emp->GetProject()->ShowProjectDetails();

}
/*************** Without smart pointers ************/
static void ShowInfo2(Employee2 *emp);
void Employees_Runnable2(void)
{
	Project2* prj = new Project2{};
	prj->SetName2("Video Decoder");
	Employee2* e1 = new Employee2{};
	e1->SetProject2(prj);
	Employee2* e2 = new Employee2{};
	e2->SetProject2(prj);
	Employee2* e3 = new Employee2{};
	e3->SetProject2(prj);

	ShowInfo2(e1);
	ShowInfo2(e2);
	prj->ShowProjectDetails2();

	/* Can we not have the employee destructor call "delete" on the project pointer?
	 * No, we cannot do that because this project pointer is shared between different employee instances.
	 * So employee instances do not really own this pointer.
	 * That is why the destruction of employees will not delete the instance of the project.
	 * Instead, the project, for instance, has to be manually deleted here.
	 */
	delete prj;
	delete e1;
	delete e2;
	delete e3;
}

void ShowInfo2(Employee2 *emp)
{
	std::cout << "Employee project details:\n";
	emp->GetProject2()->ShowProjectDetails2();
}