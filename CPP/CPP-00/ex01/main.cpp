#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			phoneBook.searchContact();
		}
		else if (command == "EXIT" || command.empty())
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return 0;
}
