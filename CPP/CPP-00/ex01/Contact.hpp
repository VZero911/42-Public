#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	void setDetails(std::string firstName, std::string lastName, std::string nickName,
					std::string phoneNumber, std::string darkestSecret);
	void display() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
};

#endif