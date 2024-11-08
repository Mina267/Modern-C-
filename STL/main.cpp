#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "AssociativeContainer.h"
#include "UnorderedContainers.h"
#include "Algorithms.h"

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

enum class SortedContact
{
    FIRST_NAME_SORT,
    LAST_NAME_SORT,
    
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

    Contact() = default;

    Contact(const std::string& FirstName, const std::string& LastName, const std::string& PriNumber, const std::string& SecNumber,
        const std::string& Email, const std::string& Address, const std::string& Company, const std::string& Group) :
        m_First_Name(FirstName),
        m_Last_Name(LastName),
        m_Primary_Number(PriNumber),
        m_Secondary_Number(SecNumber),
        m_Email(Email),
        m_Address(Address),
        m_Company(Company)
    {
        if (Group == "Family" || Group == "Friends" || Group == "Coworker" || Group == "Acquaintance")
        {
            m_Group = Group;
        }
  
        

    }

    template <typename T>
    Contact(T&& FirstName, T&& LastName, T&& PriNumber, T&& SecNumber, T&& Email, T&& Address, T&& Company, T&& Group) :
        m_First_Name{ std::forward<T>(FirstName) },
        m_Last_Name{ std::forward<T>(LastName) },
        m_Primary_Number{ std::forward<T>(PriNumber) },
        m_Secondary_Number{ std::forward<T>(SecNumber) },
        m_Email{ std::forward<T>(Email) },
        m_Address{ std::forward<T>(Address) },
        m_Company{ std::forward<T>(Company) }
    {
        if (Group == "Family" || Group == "Friends" || Group == "Coworker" || Group == "Acquaintance")
        {
            m_Group = Group;
        }



    }

    // Getter methods
    std::string getFirstName() const { return m_First_Name; }
    std::string getLastName() const { return m_Last_Name; }
    std::string getPrimaryNumber() const { return m_Primary_Number; }
    std::string getSecondaryNumber() const { return m_Secondary_Number; }
    std::string getEmail() const { return m_Email; }
    std::string getAddress() const { return m_Address; }
    std::string getCompany() const { return m_Company; }
    std::string getGroup() const { return m_Group; }

    void PrintContact() const 
    {
        std::cout << "===========================================================\n" ;
        std::cout << "First Name        : " << this->getFirstName() << std::endl;
        std::cout << "Last Name         : " << this->getLastName() << std::endl;
        std::cout << "Primary Number    : " << this->getPrimaryNumber() << std::endl;
        std::cout << "Secondary Number  : " << this->getSecondaryNumber() << std::endl;
        std::cout << "Email             : " << this->getEmail() << std::endl;
        std::cout << "Address           : " << this->getAddress() << std::endl;
        std::cout << "Company           : " << this->getCompany() << std::endl;
        std::cout << "Group             : " << this->getGroup() << std::endl;
        std::cout << "===========================================================\n";

    }


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

struct ContactHash
{
    size_t operator() (const Contact& c) const
    {
        // Combine hash values of individual member variables
        return  std::hash<std::string>{}(c.getFirstName())      ^
                std::hash<std::string>{}(c.getLastName())       ^
                std::hash<std::string>{}(c.getPrimaryNumber())  ^
                std::hash<std::string>{}(c.getSecondaryNumber())^
                std::hash<std::string>{}(c.getEmail())          ^
                std::hash<std::string>{}(c.getAddress())        ^
                std::hash<std::string>{}(c.getCompany())        ^
                std::hash<std::string>{}(c.getGroup());
    }
};


struct ContactEquality
{
    size_t operator() (const Contact& contact1, const Contact& contact2) const
    {

        return  contact1.getFirstName()         == contact2.getFirstName()          &&
                contact1.getLastName()          == contact2.getLastName()           &&
                contact1.getPrimaryNumber()     == contact2.getPrimaryNumber()      &&
                contact1.getSecondaryNumber()   == contact2.getSecondaryNumber()    &&
                contact1.getEmail()             == contact2.getEmail()              &&
                contact1.getAddress()           == contact2.getAddress()            &&
                contact1.getCompany()           == contact2.getCompany()            &&
                contact1.getGroup()             == contact2.getGroup()              
            ;

    }
};

class ContactsApp
{
private:
    std::unordered_map<std::string, Contact> Contact_List;
public:
    ContactsApp()
    {
    }

    void AddNewContact(const Contact& contact)
    {
        std::string key = contact.getFirstName() + " " + contact.getLastName();
        Contact_List[key] = contact;
    }

    // Display all contacts sorted by first or last name
    void DisplayAllContactsSorted(SortedContact SortType)
    {
        std::vector<std::string> keys;
        for (auto& i : Contact_List)
        {
            keys.push_back(i.first);
        }

        switch (SortType)
        {
        case SortedContact::FIRST_NAME_SORT:
            std::sort(keys.begin(), keys.end(), [this](const auto &key1, const auto& key2) {
                return Contact_List[key1].getFirstName() < Contact_List[key2].getFirstName();
                });
            break;
        case SortedContact::LAST_NAME_SORT:
            std::sort(keys.begin(), keys.end(), [this](const std::string& key1, const std::string& key2) {
                return Contact_List[key1].getLastName() < Contact_List[key2].getLastName();
                });
            break;
        default:
            break;
        }

        for (auto& key : keys)
        {
            Contact_List[key].PrintContact();
        }
    }

    // Display contacts with first name and primary number
    void DisplayFisrtName_PrinaryNum(void)
    {
        for (auto& i : Contact_List)
        {
            std::cout << "===========================================================\n";
            std::cout << "First Name    : " << i.second.getFirstName() << std::endl;
            std::cout << "Primary Number: " << i.second.getPrimaryNumber() << std::endl;
            std::cout << "===========================================================\n";

        }
    }

    // Display contacts from the same company
    void displayContactsByCompany(const std::string &CompanyName)
    {
        for (auto& i : Contact_List)
        {
            if (i.second.getCompany() == CompanyName)
            {
                i.second.PrintContact();
            }
        }
    }

    // Display contacts based on group type
    void displayContactsByGroup(const std::string& GroupName)
    {
        for (auto& i : Contact_List)
        {
            if (i.second.getGroup() == GroupName)
            {
                i.second.PrintContact();
            }
        }
    }

    // Search contacts by first or last name
    void searchContacts(const std::string& name) 
    {
        for (auto& i : Contact_List)
        {
            if (i.second.getFirstName() == name || i.second.getLastName() == name)
            {
                i.second.PrintContact();
            }
        }
    }


    // Display count of contacts by company and group
    void displayContactCounts() 
    {
        std::unordered_map<std::string, int> companyCounts;
        std::unordered_map<std::string, int> groupCounts;

        for (const auto& contact : Contact_List) 
        {
            companyCounts[contact.second.getCompany()]++;
            groupCounts[contact.second.getGroup()]++;
        }

        std::cout << "Contact counts by company:" << std::endl;
        for (const auto& pair : companyCounts) 
        {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Contact counts by group:" << std::endl;
        for (const auto& pair : groupCounts) 
        {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        std::cout << std::endl;

    }

    ~ContactsApp()
    {
    }


};



int main()
{
    
    std::unordered_map<std::string, Contact> Contact_List;
    
    Contact contact1("Mina", "Magdy", "+0201203591115", "+0201203595555", "Mina@gmail.com", "Cairo", "Google", "Family" );
    Contact contact2("John", "Doe", "1234567890", "", "john@example.com", "123 Main St", "ABC Company", "Friends");
    Contact contact3("Jane", "Smith", "0987654321", "", "jane@example.com", "456 Elm St", "XYZ Company", "Family");

    ContactsApp contacts;
    contacts.AddNewContact(contact1);
    contacts.AddNewContact(contact2);
    contacts.AddNewContact(contact3);
    contacts.AddNewContact(Contact("Alice", "Johnson", "9876543210", "", "alice@example.com", "789 Oak St", "ABC Company", "Coworker"));
    contacts.AddNewContact(Contact("Bob", "Brown", "0123456789", "", "bob@example.com", "321 Pine St", "XYZ Company", "Acquaintance"));


    contacts.DisplayAllContactsSorted(SortedContact::FIRST_NAME_SORT);
    std::cout << "\n\n";
    contacts.DisplayFisrtName_PrinaryNum();
    std::cout << "\n\n";
    contacts.displayContactsByCompany("ABC Company");
    std::cout << "\n\n";
    contacts.displayContactsByGroup("Family");
    std::cout << "\n\n";
    contacts.searchContacts("Magdy");
    std::cout << "\n\n";
    contacts.displayContactCounts();
    std::cout << "\n\n";
    /*
    // Generate a unique key for the contact (e.g., combination of first and last name)
    std::string key = contact1.getFirstName() + " " + contact1.getLastName();
    Contact_List[key] = contact1;
    //Contact_List.insert({ key, contact1 });


    // Add contacts to the set
    Contact_List.emplace(std::make_pair("John Doe", Contact("John", "Doe", "1234567890", "", "john@example.com", "123 Main St", "ABC Company", "Friends")));
    Contact_List.emplace(std::make_pair("Jane Smith", Contact("Jane", "Smith", "0987654321", "", "jane@example.com", "456 Elm St", "XYZ Company", "Family")));

    // Print the contacts
    for (const auto& c : Contact_List) {
        c.second.PrintContact();
        std::cout << std::endl;
    }

    

    //auto itr = Contact_List.begin();

    //itr->PrintContact();
    */
    return 0;
} 







void SET()
{

    std::unordered_set<Contact, ContactHash, ContactEquality> Contact_List;

    Contact_List.insert(Contact{ "Mina", "Magdy", "+0201203591115", "+0201203595555", "Mina@gmail.com", "Cairo", "Google", "Family" });


    // Add contacts to the set
    Contact_List.emplace("John", "Doe", "1234567890", "", "john@example.com", "123 Main St", "ABC Company", "Friends");
    Contact_List.emplace("Jane", "Smith", "0987654321", "", "jane@example.com", "456 Elm St", "XYZ Company", "Family");

    // Print the contacts
    for (const auto& contact : Contact_List) {
        contact.PrintContact();
        std::cout << std::endl;
    }



    //auto itr = Contact_List.begin();

    //itr->PrintContact();

}