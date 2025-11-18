#include <iostream>
#include <stdexcept>
#include "Contact.hpp"

std::string read_required(const std::string &prompt) {
    std::string input;
    do {
        std::cout << prompt << std::flush;
        if (!std::getline(std::cin, input))  throw std::runtime_error("EOF");
    } while (input.empty());
    return input;
}

void Contact::init_input(void) {
    set_first_name(read_required("First name: "));
    set_last_name(read_required("Last name: "));
    set_nickname(read_required("Nick name: "));
    set_phone_number(read_required("Phone Number: "));
    set_darkest_secret(read_required("Darkest Secret: "));
}
//即promptを出したいからflush

//setter
void Contact::set_first_name(const std::string &v) { first_name_ = v; }
void Contact::set_last_name(const std::string &v) { last_name_ = v; }
void Contact::set_nickname(const std::string &v) { nickname_ = v; }
void Contact::set_phone_number(const std::string &v) { phone_number_ = v; }
void Contact::set_darkest_secret(const std::string &v) { darkest_secret_ = v; }
//(std::string &..)で渡したほうが実引数のコピーを作らず参照で渡すので効率的。

//getter
std::string Contact::get_first_name(void) const { return first_name_; }
std::string Contact::get_last_name(void) const { return last_name_; }
std::string Contact::get_nickname(void) const { return nickname_; }
std::string Contact::get_phone_number(void) const { return phone_number_; }
std::string Contact::get_darkest_secret(void) const { return darkest_secret_; }
