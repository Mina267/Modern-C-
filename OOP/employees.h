#pragma once



/***************************************************/
/*************** With smart pointers ***************/
/***************************************************/



/************** shared Pointer *******************/

class Project
{
	std::string m_Name;
public:
	void SetName(const std::string& name)
	{ 
		m_Name = name;
	}
	void ShowProjectDetails() const
	{
		std::cout << "[Project Name] " << m_Name << '\n';
	}
};

class Employee
{
	std::shared_ptr<Project> m_pProject;
public:
	/* so that we can set the project any time.
	 * 
	 */
	void SetProject(const std::shared_ptr<Project>& prj)
	{
		m_pProject = prj;
	}
	/* return the project pointer that the employee holds.
	 * To avoid return a copy, return by reference.
	 */
	const std::shared_ptr<Project>& GetProject()
	{
		return m_pProject;
	}
};

void Employees_Runnable(void);


/************** Unique Pointer *******************/

class Projectunique
{
	std::string m_Name;
public:
	void SetName(const std::string& name)
	{
		m_Name = name;
	}
	void ShowProjectDetails() const
	{
		std::cout << "[Project Name] " << m_Name << '\n';
	}
};

class Employeeunique
{
	std::unique_ptr<Projectunique> m_pProject;
public:
	/* so that we can set the project any time. 
	 * To avoid copy of unique ptr pass prj variable by reference
	 */
	void SetProject(std::unique_ptr<Projectunique>& prj)
	{
		/* There is a problem here The project object created in main has been moved to the employee object.
		 * As soon as this function is invoked, it will lose
		 * The project object is now deleted and cannot be accessed again.
		 * and prj object in the main will be NULL and cannot be used. 
		 * and cannot be shared between other employee objects that will be created.
		 * because Unique Pointer does not allow sharing.
		 */
		m_pProject = std::move(prj);
	}
	/* return the project pointer that the employee holds.
	 * To avoid retutn a copy of unique smart ptr pass, return by reference.
	 */
	const std::unique_ptr<Projectunique>& GetProject()
	{
		return m_pProject;
	}
};





/***************************************************/
/*************** Without smart pointers ************/
/***************************************************/
class Project2
{
	std::string m_Name;
public:
	void SetName2(const std::string& name)
	{
		m_Name = name;
	}
	void ShowProjectDetails2() const
	{
		std::cout << "[Project Name] " << m_Name << '\n';
	}
};

class Employee2
{
	Project2* m_pProject2;
public:
	/* so that we can set the project any time. */
	void SetProject2(Project2* prj)
	{
		m_pProject2 = prj;
	}
	/* return the project pointer that the employee holds.*/
	const Project2* GetProject2()
	{
		return m_pProject2;
	}
};

void Employees_Runnable2(void);
