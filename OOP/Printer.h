#pragma once



/* Printer class can hold an integer pointer and print the value at the address. */ 
class Printer
{
	std::weak_ptr <int> m_pValue{};
	//std::shared_ptr <int> m_pValue{};
public:

	/* Problem to use share pointer instead of weak pointer that reference count will become two 
	 * Then memory will not release when we assigned null in app beacuse there still share Exist
	 */
	//void SetValue(std::shared_ptr <int> p)
	void SetValue(std::weak_ptr <int> p)
	{

		m_pValue = p;

	}
	void Print()
	{
		if (m_pValue.expired())
		{


			std::cout << "Resource is no longer available" << std::endl;
		}
		else
		{
			auto sp = m_pValue.lock();
			std::cout << "Value id: " << *sp << std::endl;
			std::cout << "Ref count: " << sp.use_count() << std::endl;


		}
	}
};

void Printer_Runnable(void);
