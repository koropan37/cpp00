#include <iostream>
#include "Contact.hpp"

Contact::Contact()
	: first_name_()
	, last_name_()
	, nickname_()
	, phone_number_()
	, darkest_secret_()
	{}

//std::stringのような変数はコンストラクタを書かなくても「デフォルトコンストラクタ」が
//自動で用意される(int doubleなどは未初期化)

std::string Contact::get_first_name(void) { return first_name_; }
std::string Contact::get_last_name(void) { return last_name_; }
std::string Contact::get_nickname(void) { return nickname_; }
std::string Contact::get_phone_number(void) { return phone_number_; }
std::string Contact::get_darkest_secret(void) { return darkest_secret_; }

void Contact::set_first_name(const std::string &v) { first_name_ = v; }
void Contact::set_last_name(const std::string &v) { last_name_ = v; }
void Contact::set_nickname(const std::string &v) { nickname_ = v; }
void Contact::set_phone_number(const std::string &v) { phone_number_ = v; }
void Contact::set_darkest_secret(const std::string &v) { darkest_secret_ = v; }
