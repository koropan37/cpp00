#ifndef PHONE_BOOK_HPP_
#define PHONE_BOOK_HPP_

#include "Contact.hpp"

#define PHONE_BOOK_SIZE 8
#define DETAILS_COLUMN 16
class PhoneBook{
 private:
	Contact contacts_[PHONE_BOOK_SIZE];
	int 	next_i_;
	int		count_;

	void 		print_info();
	void 		print_open_info(Contact &contact, int index);
	std::string trim_info(const std::string &str);
	int 		input_index();
	void 		print_details(int index);
 public:
	PhoneBook();

	void run();
	void add();
	void search();

};

#endif
