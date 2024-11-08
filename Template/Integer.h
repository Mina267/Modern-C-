#pragma once


#include <iostream>


class Integer {
	/* Private members */
	int* m_pInt;
public:
	//Default constructor
	Integer();

	//Parameterized constructor
	/* explicit use to Prevent implicit costing. */
	/* explicit */ Integer(int value);

	//Copy constructor
	Integer(const Integer& obj);

	//Move constructor
	Integer(Integer&& obj) noexcept(true);



	int GetValue()const;

	void SetValue(int value);

	~Integer() noexcept(true);

	/* Operators overloading */

	/* Pluse operator */
	Integer operator +(const Integer& n) const;

	/* Pre-increment */
	Integer& operator ++();

	/* Post-increment -> int to make post has different signature */
	Integer operator ++(int);

	/* Bool */
	bool operator ==(const Integer& obj) const;

	/* Assignment operator */
	// Copy assignment
	Integer& operator=(const Integer& obj);

	// Move assignment
	Integer& operator=(Integer&& obj) noexcept(true);

	/* explicit keyword use so If you want to perform a type conversion,
	 * you'll have to explicitly mention the cast.
	 * compiler can not perform implicit casting due to use explicit keyword in function.
	 */
	explicit operator int();


	friend std::istream& operator >> (std::istream& input, Integer& a);


};
/* Overload operator with primitive type int and Integer */
Integer operator +(int x, const Integer& y);
/* Friend global function to the class */
std::istream& operator >> (std::istream& input, Integer& a);


