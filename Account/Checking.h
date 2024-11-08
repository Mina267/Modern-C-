#pragma once
#include "Account.h"
class Checking :
    public Account
{
    float m_MinimumBalance;

public :

    /* Using keywords will lead to the child class inheriting all the constructors of the parent class. 
    * This will be Equivalent to  manually invoke the constructor of the partent class in 
    * the initializer list of Checking constructor*/
    using Account::Account;

    Checking(const std::string& name, float balance, float minBalance);
    ~Checking();

    /* Reimplement the withdraw function from partent Account class */
    void Withdraw(float amount) override;

    float GetMinimumBalance() const;

};



