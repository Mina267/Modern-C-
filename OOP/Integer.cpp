#include "Integer.h"
#include <iostream>
//Default constructor
Integer::Integer()
{
	// Debuging
	std::cout << "Integer()" << std::endl;

	// Create Integer in head and store zero
	m_pInt = new int(0);
}

//Parameterized constructor
Integer::Integer(int value)
{
	// Debuging
	std::cout << "Integer(int)" << std::endl;

	m_pInt = new int(value);
}

//Copy constructor
/* arguments is the original object that we want to copy */
Integer::Integer(const Integer& obj) 
{
	// Debuging
	std::cout << "Integer(const Integer&)" << std::endl;
	/* allocate new memory to preform deep copy */
	m_pInt = new int(*obj.m_pInt); // derefence the value original object and copy it into new location in memory
}

//Move constructor
/* Will steal the resources from object
 * This is going to be a much faster operation than copying, 
 * In copy semantics, Will allocate new memory and then copy the data here.
 * We do not have to allocate any new resources.
 * Instead, we just copy the data from the source object into the target object.
 */
Integer::Integer(Integer&& obj) noexcept(true)
{
	// Debuging
	std::cout << "Integer(int&&)" << std::endl;
	/* we are going to steal the resources fom Object 
	 * and we'll do that by implementing a shallow copy
	 */
	m_pInt = obj.m_pInt;
	/* And to let the other object know that we have stolen
	 * the resources we will assign NULL to the pointer,
	 * so this way when the other object is destroyed
	 * its destructive will not crush the call 
	 * 
	 */
	obj.m_pInt = nullptr;
}

// Copy assignment
Integer& Integer::operator=(const Integer& obj)
{
	// Debuging
	std::cout << "operator=(const Integer& obj)" << std::endl;
	/* check for object gets assigned to itself.
	 * this will cause the value be garbage because we delete m_pInt first
	 */
	if (this == &obj)
	{
		return *this;
	}
	/* And what we need to do is, we need to first
	* delete the memory for the existing object.
	* Otherwise it will cause a memory leak
	*/
	delete m_pInt;
	m_pInt = new int(*obj.m_pInt);
	return *this;
}

// Move assignment
Integer& Integer::operator=(Integer&& obj) noexcept(true)
{
	// Debuging
	std::cout << "operator=(Integer&& obj)" << std::endl;
	/* check for self assignment */
	if (this == &obj)
	{
		return *this;
	}
	else
	{
		delete m_pInt;
		m_pInt = obj.m_pInt;
		obj.m_pInt = nullptr;
		return *this;
	}

}

int Integer::GetValue() const
{
	return *m_pInt;
}

void Integer::SetValue(int value)
{
	if (this->m_pInt == nullptr)
	{
		m_pInt = new int(value);
	}
	else
	{
		// assign the value to the pointer variable.
		*m_pInt = value;
	}
	
}


/* The compiler can use the type conversion operator function to convert the Integer object into*/
Integer::operator int()
{
	return *m_pInt; 
}



Integer::~Integer() noexcept(true)
{
	// Debuging
	std::cout << "~Integer()" << std::endl;

	/* This will simply free the memory that was allocated for the integer pointer. */
	delete m_pInt;
}

Integer& Integer::operator++()
{
	++(*m_pInt);
	/* Return by reference, it returns an L-value. */
	return (*this);
}

Integer Integer::operator++(int)
{
	Integer tmp(*this);
	++(*m_pInt);
	/* Note that this temeect is a temporary variable. So, we cannot return it by reference. */
	return tmp;
}

bool Integer::operator==(const Integer& obj) const
{
	return (*m_pInt == *obj.m_pInt);
}



/* Operator overloading member Function
 * so it seems that we are
 * Adding two objects but in reality the compiler will
 * internally invoke the overloaded operator function.
 */
Integer Integer::operator+(const Integer& n) const
{
	Integer tmp;
	*tmp.m_pInt = *m_pInt + *n.m_pInt;
	return tmp;
}


Integer operator +(int x, const Integer& y)
{
	Integer	temp;
	temp.SetValue(x + y.GetValue());
	return temp;
}

std::istream& operator >> (std::istream& input, Integer& a)
{
	int x;
	input >> x;
	*a.m_pInt = x;
	return input;
}



