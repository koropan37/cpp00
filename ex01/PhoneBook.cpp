#include <iostream>
#include "PhoneBook.hpp"

void PhoneBook::run() {
	std::string input;

	std::cout << "PhoneBook" << std::endl;
	try {
		while(1) {
			if(std::cin.eof()) throw std::runtime_error("EOF");
			std::cout << "Command: ";
			std::getline(std::cin, input);
			if(input == "ADD")
				add();
			else if(input == "SEARCH")
				search();
			else if(input == "EXIT")
				break;
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void PhoneBook::add() {

}

void PhoneBook::search() {
	
}
