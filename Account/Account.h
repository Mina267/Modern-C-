#pragma once
class Account
{
	std::string m_Name;
	int m_AccNo;
	static int s_ANGenerator;

protected:
	float m_Balance;

public:
	/* Account initialized by take name of account owner and initial balance */
	Account(const std::string &name, float balance);
	/* so when we call delete with pointer to account object will invoke needed destructor for child class 
	 * If we not use virtaul only destructor of parent class will invoke when we delete pointer to child class */
	virtual ~Account();
	/* Add Const because this function did not modify the state of the class */
	const std::string GetName()const;
	float GetBalance()const;
	int GetAccountNo()const;


   /*
	* The AccumulateInterest, GetInterestRate, and Withdraw functions are overwritten by the child classes.
	* And if these functions are invoked on the base class as a reference, the compiler will invoke
	* member function of base class, not of child
	* The virtual keyboard used it allows derived classes to override 
	* that function with their own implementations. 
	*/
	/*
	* when a function is marked as
	* virtual in a class, then the compiler automatically adds a hidden pointer to the class and
	* that pointer is called as the virtual pointer.
	* And this virtual pointer is going to increase the size of the class and the objects by the size of the pointer.
	* In Conclusion: this allow child class to overRide parent member function, but it must be protected or puplic function
	*/
	virtual void AccumulateInterest();
	virtual void Withdraw(float amount);
	void Deposit(float amount);
	virtual float GetInterestRate()const;
	/* The concept implemented here is polymorphism. With polymorphism, 
	 * you send a message to an object that represents different objects, 
	 * and the message will automatically go to the correct object, providing the right behavior.
	 */
};

