#include <iostream>
#include <string>
#include "Savings.h"

/* We should manually invoke the constructor of the partent class in the initializer list; 
 * if we do not do this, the compiler will automatically invoke the default constructor. 
 */
Savings::Savings(const std::string &name, float balance, float rate): Account(name, balance), m_Rate(rate)
{

}

Savings::~Savings()
{
}

float Savings::GetInterestRate() const
{
	return m_Rate;
}

void Savings::AccumulateInterest()
{
	m_Balance += (m_Balance * m_Rate);
}
