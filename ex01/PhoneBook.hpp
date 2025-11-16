#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

#define PHONE_BOOK_SIZE
class PhoneBook{
	private:
		Contact contacts_[PHONE_BOOK_SIZE];
	public:
		PhoneBook();
		void run();
		void add();
		void search();

};

#endif
