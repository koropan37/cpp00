#ifndef CONTACT_NPP_
#define CONTACT_NPP_

#include <string>

class Contact{
 private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;

 public:
	void init_input();

	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_phone_number() const;
	std::string get_darkest_secret() const;

	void set_first_name(const std::string &v);
	void set_last_name(const std::string &v);
	void set_nickname(const std::string &v);
	void set_phone_number(const std::string &v);
	void set_darkest_secret(const std::string &v);
};

		std::string read_required(const std::string &prompt);

#endif

//	getterでは基本的に末尾にconstをつけたほうがいい
//	安全性向上やconstなオブジェクトから呼び出せるようになる
