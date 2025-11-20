#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() :next_i_(0), count_(0){}

//	std::stringのような変数はコンストラクタを書かなくても自動で初期化してくれるが
//	int doubleなどは未初期化なので明示的に書く必要あり

//	func() : ..., ...{} はメンバ初期化子リストで、直接初期化できる
//	PhoneBook::PhoneBook(){next_i_ = 0} 組み込み型ならほとんど差はないが、
//	クラス型のメンバ（std::string 等）はまずデフォルト構築され、
//	その後に代入されるため余計な構築/代入が発生する（コストがかかる）

void PhoneBook::run() {
	std::string input;

	try {
		while(true) {
			std::cout << "Command (ADD or SEARCH or EXIT): " << std::flush;
			if(!std::getline(std::cin, input)) throw std::runtime_error("EOF");

			if	   (input == "ADD") 	add();
			else if(input == "SEARCH") 	search();
			else if(input == "EXIT") 	break;
			else 	std::cerr << "Invalid Input\n";
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

//throwで例外(通常は値)を投げてtryで例外を監視、catchで例外を受け取って処理
//catch は const 参照で受ける
//exception &eは標準例外をまとめて扱える(個別にしたいならその前で定義)

void PhoneBook::add() {
	contacts_[next_i_ % PHONE_BOOK_SIZE].init_input();
	++next_i_;
	if(count_ < PHONE_BOOK_SIZE) ++count_;
}

void PhoneBook::search() {
	int index;
	print_info();
	index = input_index();
	print_details(index);
}

void PhoneBook::print_info() {
	std::cout
		<< "|" << std::setw(10) << "Index"
		<< "|" << std::setw(10) << "First Name"
		<< "|" << std::setw(10) << "Last Name"
		<< "|" << std::setw(10) << "Nickname"
		<< "|" << std::endl;
	for(int i = 0; i < PHONE_BOOK_SIZE; i++)
		print_open_info(contacts_[i], i);
}
//std::setwで幅指定

void PhoneBook::print_open_info(Contact &contact, int index){
	std::cout
		<< "|" << std::right << std::setw(10) << index + 1
		<< "|" << std::right << std::setw(10) << trim_info(contact.get_first_name())
		<< "|" << std::right << std::setw(10) << trim_info(contact.get_last_name())
		<< "|" << std::right << std::setw(10) << trim_info(contact.get_nickname())
		<< "|" << std::endl;
}

std::string PhoneBook::trim_info(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

int PhoneBook::input_index() {
	int idx;

	while(true){
		std::stringstream ss(read_required("Index> "));
		if(ss >> idx && (ss >> std::ws).eof() \
			&& 1 <= idx && idx <= PHONE_BOOK_SIZE)
			return idx;
		std::cerr << "Invalid index" << std::endl;
	}
}
//stringstreamで文字列を操作, データ型によって値を判断
//std::wsで後ろの空白を飛ばして、eofで終わるか(余計な文字がないか)チェック

void PhoneBook::print_details(int index) {
	int i = index - 1;

	if (index < 1 || index > count_) {
		std::cerr << "No contact index" << std::endl;
		return;
	}
	std::cout
		<< std::left
		<< std::setw(DETAILS_COLUMN) << "Index: " 		   << index << "\n"
		<< std::setw(DETAILS_COLUMN) << "First Name: " 	   << contacts_[i].get_first_name() << "\n"
		<< std::setw(DETAILS_COLUMN) << "Last Name: "	   << contacts_[i].get_last_name() << "\n"
		<< std::setw(DETAILS_COLUMN) << "Nickname: " 	   << contacts_[i].get_nickname() << "\n"
		<< std::setw(DETAILS_COLUMN) << "Phone number: "   << contacts_[i].get_phone_number() << "\n"
		<< std::setw(DETAILS_COLUMN) << "darkest secret: " << contacts_[i].get_darkest_secret()
		<< std::endl;
}
