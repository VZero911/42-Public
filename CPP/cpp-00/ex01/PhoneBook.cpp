#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : currentIndex(0), totalContacts(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

std::string PhoneBook::truncateString(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

std::string PhoneBook::promptInput(const std::string& fieldName)
{
    std::string input;
    std::cout << "Enter " << fieldName << ": ";
    while (std::getline(std::cin, input))
    {
        if (!input.empty())
            return input;
        std::cout << fieldName << " cannot be empty. Enter " << fieldName << ": ";
    }
    return "";
}

void PhoneBook::addContact(void)
{
    Contact newContact;
    std::string input;

    if ((input = promptInput("first name")).empty()) return;
    newContact.setFirstName(input);

    if ((input = promptInput("last name")).empty()) return;
    newContact.setLastName(input);

    if ((input = promptInput("nickname")).empty()) return;
    newContact.setNickname(input);

    if ((input = promptInput("phone number")).empty()) return;
    newContact.setPhoneNumber(input);

    if ((input = promptInput("darkest secret")).empty()) return;
    newContact.setDarkestSecret(input);

    contacts[currentIndex] = newContact;
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;

    std::cout << "Contact added successfully!" << std::endl;
}


void PhoneBook::displayContactsTable(void) const
{
    std::cout << std::right << std::setw(10) << "Index" << "|";
    std::cout << std::right << std::setw(10) << "First Name" << "|";
    std::cout << std::right << std::setw(10) << "Last Name" << "|";
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << std::right << std::setw(10) << i << "|";
        std::cout << std::right << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
        std::cout << std::right << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
        std::cout << std::right << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index) const
{
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

bool PhoneBook::isValidIndex(const std::string &input, int &index) const
{
    if (input.length() != 1 || !std::isdigit(input[0]))
        return false;
    
    index = input[0] - '0';
    return (index >= 0 && index < totalContacts);
}

void PhoneBook::searchContact(void) const
{
    if (totalContacts == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    
    displayContactsTable();
    std::string input;
    int index;
    std::cout << "Enter the index of the contact to display: ";
    if (!std::getline(std::cin, input))
        return;
    
    if (isValidIndex(input, index))
        displayContactDetails(index);
    else
        std::cout << "Invalid index." << std::endl;
}

void PhoneBook::run(void)
{
    std::string command;
    
    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true)
    {
        std::cout << "Enter a command: ";
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl << "EOF detected. Goodbye!" << std::endl;
            break;
        }
        if (command == "ADD")
            addContact();
        else if (command == "SEARCH")
            searchContact();
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (!command.empty())
            std::cout << "Unknown command. Available commands: ADD, SEARCH, EXIT" << std::endl;
    }
}