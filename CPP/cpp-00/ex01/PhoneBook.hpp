#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook
{
    private:
        Contact contacts[8];
        int currentIndex;
        int totalContacts;
        
        std::string truncateString(const std::string &str) const;
        void displayContactsTable(void) const;
        void displayContactDetails(int index) const;
        bool isValidIndex(const std::string &input, int &index) const;
        std::string promptInput(const std::string& fieldName);

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        
        void addContact(void);
        void searchContact(void) const;
        void run(void);
};

#endif