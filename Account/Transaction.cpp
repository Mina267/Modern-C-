#include <iostream>
#include <string>
#include <typeinfo>

#include "Account.h"
#include "Transaction.h"
#include "Checking.h"

/* A base class point of reference can point to any of its child class objects.
 * So that's why we will replace this checking with account in prototype.
 * by this way we can pass either Checking class or saving class to Transact function
 */
void Transact(Account* pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Intial balance: " << pAccount->GetBalance() << std::endl;
	pAccount->Deposit(100);
	pAccount->AccumulateInterest();


	/* If we want to withdraw the amount, we will first check the minimum balance of the checking account.
	 * This will have to invoke the function to get the minimum balance of checking.
	 * And if we tried to invoke that from a point, we could not because the function GetMinimumBlance is not
	 * part of the account class, plus that is why we will have to apply a downcast on the account pointer. 
     * and get the checking pointer, then go through that point so we can invoke the get minimum balance function. 
	 * These cast may cause problem Beacuse may be we did not pass checking pointer to function and pass saving pointer
	 */

	//Checking* pChecking = static_cast<Checking*>(pAccount);
	//std::cout << "Minimum balance of checking: " << pChecking->GetMinimumBalance() << std::endl;

	/* Use Typied to slove this problem */
	//if (typeid(*pAccount) == typeid(Checking))
	//{
	//	Checking* pChecking = static_cast<Checking*>(pAccount);
	//	std::cout << "Minimum balance of checking: " << pChecking->GetMinimumBalance() << std::endl;
	//}

	/* This condition could be replaced by dynamic casting, and dynamic casting will automatically check if this casting is applicable or not. */
	Checking* pChecking = dynamic_cast<Checking*>(pAccount);
	if (pChecking != nullptr)
	{
		std::cout << "Minimum balance of checking: " << pChecking->GetMinimumBalance() << std::endl;
	}



	pAccount->Withdraw(170);
	std::cout << "Interset Rate: " << pAccount->GetInterestRate() << std::endl;
	std::cout << "Final balance: " << pAccount->GetBalance() << std::endl;

}
 



void Transact(Account& pAccount)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Intial balance: " << pAccount.GetBalance() << std::endl;
	pAccount.Deposit(100);
	pAccount.AccumulateInterest();


	

	 /* This condition could be replaced by dynamic casting, and dynamic casting will automatically check if this casting is applicable or not. */
	//Checking& pChecking = dynamic_cast<Checking&>(pAccount);
	//std::cout << "Minimum balance of checking: " << pChecking.GetMinimumBalance() << std::endl;

	try {
		Checking& pChecking = dynamic_cast<Checking&>(pAccount);
		std::cout << "Minimum balance of checking: " << pChecking.GetMinimumBalance() << std::endl;
	}
	catch (const std::bad_cast& e) {
		std::cout << "Account is not a Checking account." << std::endl;
	}


	pAccount.Withdraw(170);
	std::cout << "Interset Rate: " << pAccount.GetInterestRate() << std::endl;
	std::cout << "Final balance: " << pAccount.GetBalance() << std::endl;

}