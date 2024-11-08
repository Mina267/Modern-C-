#pragma once
#include <iostream>
#include <string>

enum class ContactType
{
    FIRST_NAME,
    LAST_NAME,
    PRIMARY_NUMBER,
    SECONDARY_NUMBER,
    EMAIL,
    ADDRESS,
    COMPANY,
    GROUP
};

class Contact
{
private:
    std::string m_First_Name;
    std::string m_Last_Name;
    std::string m_Primary_Number;
    std::string m_Secondary_Number;
    std::string m_Email;
    std::string m_Address;
    std::string m_Company;
    std::string m_Group;

public:
    Contact(std::string &FirstName, std::string &LastName, std::string &PriNumber, std::string &SecNumber,
        std::string &Email, std::string &Address, std::string &Company, std::string &Group) :
        m_First_Name(FirstName),
        m_Last_Name(LastName),
        m_Primary_Number(PriNumber),
        m_Secondary_Number(SecNumber),
        m_Email(Email),
        m_Address(Address),
        m_Company(Company),
        m_Group(Group)
    {}

    // Getter methods
    std::string getFirstName() const { return m_First_Name; }
    std::string getLastName() const { return m_Last_Name; }
    std::string getPrimaryNumber() const { return m_Primary_Number; }
    std::string getSecondaryNumber() const { return m_Secondary_Number; }
    std::string getEmail() const { return m_Email; }
    std::string getAddress() const { return m_Address; }
    std::string getCompany() const { return m_Company; }
    std::string getGroup() const { return m_Group; }

    // Method to edit contact data
    void editData(ContactType DataType, const std::string& NewData)
    {
        switch (DataType)
        {
        case ContactType::FIRST_NAME:
            m_First_Name = NewData;
            break;
        case ContactType::LAST_NAME:
            m_Last_Name = NewData;
            break;
        case ContactType::PRIMARY_NUMBER:
            m_Primary_Number = NewData;
            break;
        case ContactType::SECONDARY_NUMBER:
            m_Secondary_Number = NewData;
            break;
        case ContactType::EMAIL:
            m_Email = NewData;
            break;
        case ContactType::ADDRESS:
            m_Address = NewData;
            break;
        case ContactType::COMPANY:
            m_Company = NewData;
            break;
        case ContactType::GROUP:
            m_Group = NewData;
            break;
        default:
            break;
        }
    }
};
