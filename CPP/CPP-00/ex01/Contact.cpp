#include "Contact.hpp"
#include <iostream>

Contact::Contact() : first_name(""), last_name(""), nickname(""),
					 phone_number(""), darkest_secret("") {}

void Contact::setDetails(std::string firstName, std::string lastName, std::string nickName,
						 std::string phoneNumber, std::string darkestSecret)
{
	first_name = firstName;
	last_name = lastName;
	nickname = nickName;
	phone_number = phoneNumber;
	darkest_secret = darkestSecret;
}

void Contact::display() const
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickname() const { return nickname; }
