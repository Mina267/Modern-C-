
#include "Account.h"
class Savings :
    public Account
{
    /* Savings accounts have interest rates 
     * will be used to accumulate the interest into the savings account.
     */
    float m_Rate;
public:
    Savings(const std::string &name, float balance, float rate);
    ~Savings();

    float GetInterestRate()const override;
    void AccumulateInterest() override;

    void AdditionalFunc() {
        std::cout << "AdditionalFunc\n";
    }
};
 