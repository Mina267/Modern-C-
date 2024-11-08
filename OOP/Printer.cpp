#include <iostream>
#include "Printer.h"

/* Without using smart pointer */






// week pointer
void Printer_Runnable(void)
{
	Printer prn;
	int num{};
	std::cin >> num;
	std::shared_ptr<int> p{ new int{ num } };
	prn.SetValue(p);
	/* Check if number larger than 10 */
	std::cout << "Ref main: " << p.use_count() << std::endl;


	if (*p > 10)
	{
		
		p = nullptr;
	}
	prn.Print();

}






// Shared pointer
void Printer_Runnable2(void)
{
	Printer prn;
	int num{};
	std::cin >> num;
	std::shared_ptr<int> p{ new int{ num } };
	prn.SetValue(p);
	/* Check if number larger than 10 */
	if (*p > 10)
	{
		/* will delete the data and set to nullptr in local 
		 * but class member variable will not free beacuse the reference count will not bee equal zero
		 * due to copy created will invoke function prn.SetValue(p); so memory will not deleted at this line of code.
		 * So even if you assign null pointer to this smart pointer object, the reference count is only decreminted
		 * by one. So the underlying memory is not released.
		 * So, we need way to not creating copy when we call "prn.SetValue(p);" function
		 */
		p = nullptr;
	}
	/* and also determine if data we access in Shared pointer in "prn.Print();" still exist or not */
	prn.Print();

}

/* Without using smart pointer */
void Printer_RunnableNot(void)
{
	Printer prn;
	int num{};
	std::cin >> num;
	int* p = new int{ num };
	//prn.SetValue(p);
	/* Check if number larger than 10 */
	if (*p > 10)
	{
		/* Data that pointer class pointed to is deleted
		 * put pointer class still pointed to that deleted memory
		 */
		delete p;
		/* this will set the local pointer variable "p" to nullptr 
		 * put class member variable pointer will still the same pointed to deleted memory
		 * So we want to link these two pointer some how.
		 */
		p = nullptr;
	}
	/* So here m_pValue will be dangled pointer 
	 * point to deleted memory that freed
	 */
	prn.Print();
	delete p;

}