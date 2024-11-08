#include <iostream>
#include <string>
#include "Checking.h"

/* manually invoke the constructor of the partent class in the initializer list of Checking constructor */
Checking::Checking(const std::string& name, float balance, float minBalance): Account(name, balance), 
m_MinimumBalance(minBalance)
{

}

Checking::~Checking()
{
}

void Checking::Withdraw(float amount)
{
	/* Will prevent from withdraw the money if the balance will below 50 */
	if ((m_Balance - amount) > m_MinimumBalance)
	{
		/* Child class can call any of class base member function "Parent Account"
		 * Scope "Account:: " is important if we did not put it, the member function of child class
		 * will invoke make Recursion function 
		 */
		Account::Withdraw(amount);
	}
	else
	{
		std::cout << "Inaviled amount!" << std::endl;
	}
}

/* Return min balance */
float Checking::GetMinimumBalance() const
{
	return m_MinimumBalance;
} 
