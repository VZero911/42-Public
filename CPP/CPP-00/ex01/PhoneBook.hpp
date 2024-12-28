#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contact_count;

	public:
		PhoneBook();
		void addContact();
		void searchContact() const;
		void displayContacts() const;
};

#endif
