#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contact_count(0) {}

void PhoneBook::addContact()
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickName.empty() ||
		phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "All fields must be filled!" << std::endl;
		return;
	}

	contacts[contact_count % 8].setDetails(firstName, lastName, nickName, phoneNumber, darkestSecret);
	contact_count++;
}

void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|" 
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].getFirstName().empty())
		{
			std::cout << std::setw(10) << i + 1 << "|"
					  << std::setw(10) << (contacts[i].getFirstName().substr(0, 9) + (contacts[i].getFirstName().length() > 9 ? "." : "")) << "|"
					  << std::setw(10) << (contacts[i].getLastName().substr(0, 9) + (contacts[i].getLastName().length() > 9 ? "." : "")) << "|"
					  << std::setw(10) << (contacts[i].getNickname().substr(0, 9) + (contacts[i].getNickname().length() > 9 ? "." : "")) << "|"
					  << std::endl;
		}
	}
}

void PhoneBook::searchContact() const
{
	int index;
	std::cout << "Enter index of contact to display: ";
	std::cin >> index;
	std::cin.ignore();

	if (index < 1 || index > 8 || contacts[index - 1].getFirstName().empty())
	{
		std::cout << "Invalid index!" << std::endl;
	}
	else
	{
		contacts[index - 1].display();
	}
}
