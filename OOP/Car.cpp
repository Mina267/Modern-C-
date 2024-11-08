#include "Car.h"
#include <iostream>


int Car::totalCount;

/* Car(0): delegating constructor */
Car::Car():Car(0)
{
	std::cout << "Constructor1" << std::endl;
	//fuel = 0;
	//speed = 0;
	//passengers = 0;
}

/* Car(amount, 0): delegating constructor */
Car::Car(float amount):Car(amount, 0)
{
	std::cout << "Constructor2" << std::endl;

	++totalCount;
	//fuel = amount;
	//speed = 0;
	//passengers = 0;

}

/* So, the call to any of these constructors will always
 * initialize the state of the object using this code.
 * this avoid multiple code intialization of member variables
 * The code is no longer duplicated.
 */
Car::Car(float amount, int pass)
{
	std::cout << "Constructor3" << std::endl;
	++totalCount;
	fuel = amount;
	speed = 0;
	passengers = pass;
}
 
Car::~Car()
{
	--totalCount;
	std::cout << "~Car()" << std::endl;
}

void Car::FillFuel(float amount)
{
	fuel = amount;
}



void Car::Brake()
{
	speed = 0;
}

void Foo(const Car& car)
{

}

void Car::Accelerate()
{
	/* Access using this pointer "Constant pointer can not change its address" use to access call memebers
	 * You did not need to use this pointer to access member of class compiler will implicity use it
	 */
	this->speed++;
	this->fuel -= 0.5f;
}
void Car::AddPassemgers(int passengers)
{
	/* Use this pointer to Distinguish between local variable and class members */
	this->passengers = passengers;

	/* Use to pass car object as arrgument */
	Foo(*this);
}

/* All the member functions that do not modify the state of the object should be qualified with the const keyword.
 * and const function can not modify member variables -> because actually this pointer in this function implicit as const pointer to object
 * And when object created in main as constant Ex. const Car car  
 * Can only invoke function that did not modify the state of the object " const " 
 */
void Car::Dashboard() const
{
	//fuel++;
	//this->fuel++;
	std::cout << "Fuel: " << fuel << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Passengers: " << passengers << std::endl;

}

/* invoke in main->Car::ShowCount();
 * Do not receive this pointer
 * they can access only static members of the class.
 */
void Car::ShowCount()
{
	std::cout << "totalCount: " << totalCount << std::endl;
}




















