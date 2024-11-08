#pragma once
class Car {
private:
	/* Can intialized Variables in During decleartion instead of using constructor
	 * This method known as Non-Static Data Member Initializers.
	 * this code of Initializing placed in constructor, if user not create of compiler will create one 
	 * the compiler will automatically generate the code that initializes these member variables 
	 * and will insert that code in both the constructors
	 * Note that: constructor has higher precedence 
	 * If data init in decleartion and in constructor, constructor values will used 
	 */
	float fuel{ 0 };
	float speed{ 0 };
	int passengers{ 0 };
	int arr[5] = { 1, 2, 3 };
	int* p{}; // Pointer initialized to NULL
	static int totalCount; // Functionality as in c

	/* Auto can not use here with Non-Static Data Member Initializers. */
	// auto i = 5;
public:
	/* Call of constructor and destructor is automatically invoke by compiler 
	 * when the instance is created and when program end*/
	// constructor
	Car();
	// OverLoad constructor
	Car(float amount);
	Car(float amount, int pass);

	// destructor
	~Car();
	// Defined in class, it will automatically be inline.
	void FillFuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassemgers(int count);
	/* const member function only that did not modify any member variables
	 * And when new object decleared as const this functions can only invoked
	 */
	/*
	 * Do not receive this pointer
	 * they can access only static members of the class.
	 */
	void Dashboard() const;

	static void ShowCount(); 

};