
#include <iostream>
#include "Integer.h"
#include "App1.h"

void Display(Integer* p)
{
	if (p == nullptr)
	{
		/* Do nothing */
	}
	else
	{
		std::cout << "Value: " << p->GetValue() << std::endl;
	}
}


Integer* GetPointer(int value)
{
	return (new Integer{ value });
}

void Operate(int value)
{ 
	/* Variable name that is going to be unique pointer has explicit constructor.
	 * That is why we cannot use this assignment to initialize.
	 * Instead, we will use direct initialization like this.
	 */
	std::unique_ptr<Integer> p{ GetPointer(value) };
	if (p == nullptr)
	{
		/* Reset will do two things:
		 * first if the smart pointer object holds an existing pointer, that will be deleted
		 * then it'll take ownership of this new pointer.
		 */
		p.reset(new Integer{ value });
	}

	p->SetValue(300);
	/* get will return the underlying pointer so you can pass 
	 * this pointer in any function that does not accept the unique point of.
	 */
	Display(p.get());
	p = nullptr;
	/* we have called reset here, reset will instantly delete the underlying pointer 
	 * and then take ownership of the new pointer. 
	 * So there is no need of assign nullptr as we do in pervious line now.
	 */
	p.reset(new Integer{});
	*p = __LINE__;
	Display(p.get());

	/* if we compiled the code will give an error. 
	 * Beacuse attempting to reference a deleted function, the copy constructor of the unique pointer is deleted.
	 * Therefore, you cannot create a copy of Unique Point of Object.
	 * Notice that we don't use this smart pointer after the store function anyway, at the end of the scope,
	 * this is going to be destroyed so we don't need it after store function.
	 */ 
	//Store(p);

	/* This will move the state of this object into this object.
	 * And when this object is destroyed, it will free the underlying memory.
	 * It will simply give up the ownership of the underlying point to.
	 * Therefore, after this statement, you should not try to access the underlying point inside this smart point to.
	 * Although you can reuse this object and store a new pointer inside it by simply calling it.
	 * So remember, you cannot create a copy of Unique Pointer, but you can always move it.
	 */

	//Store(std::move(p));

	/* or we can pass it by reference 
	 * And the advantage is that you can still use this smart pointer after the stored function.
	 */
	StoreRef(p);
	/* it will not work if we moved */
	*p = 200;
	
}

void StoreRef(std::unique_ptr<Integer> &p)
{
	std::cout << "storing data into a file: " << p->GetValue() << std::endl;
}

void Store(std::unique_ptr<Integer> p)
{
	std::cout << "storing data into a file: " << p->GetValue() << std::endl;
}
 

/* Complex to manage memory */
void OperateOld(int value)
{
	Integer* p = GetPointer(value);
	if (p == nullptr)
	{
		p = (new Integer{ value });
	}

	p->SetValue(300);
	Display(p);
	delete p;
	p = nullptr;
	p = new Integer{ };
	*p = __LINE__;
	Display(p);
	delete p;
}