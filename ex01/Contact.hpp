#ifndef CONTACT_NPP
#define CONTACT_NPP

#include <string>

class Contact{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;

	public:
		Contact();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_darkest_secret();

		void set_first_name(const std::string &v);
		void set_last_name(const std::string &v);
		void set_nickname(const std::string &v);
		void set_phone_number(const std::string &v);
		void set_darkest_secret(const std::string &v);
};

#endif
