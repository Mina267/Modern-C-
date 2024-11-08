#include <iostream>
#include <string>
#include "Account.h"


int Account::s_ANGenerator = 1000;
Account::Account(const std::string& name, float balance):
	/*Initialize the member variable through member Initialize list */
	m_Name(name), m_Balance(balance)
{
	m_AccNo = ++s_ANGenerator;
}

Account::~Account()
{
}

const std::string Account::GetName() const
{
	return m_Name;
}

float Account::GetBalance() const
{
	return m_Balance;
}

int Account::GetAccountNo() const
{
	return m_AccNo;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(float amount)
{
	if (amount < m_Balance)
	{
		m_Balance -= amount;
	}
	else
	{
		std::cout << "Insufficient balance!" << std::endl;
	}
}

void Account::Deposit(float amount)
{
	m_Balance += amount;

}

float Account::GetInterestRate() const
{
	return 0.0f;
}
