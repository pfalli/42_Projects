/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:59:25 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/18 10:59:25 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Contact::Contact(void){
    std::cout << "Costructor called" << std::endl;
}

Contact::~Contact(void){
    std::cout << "Decostructor called" << std::endl;
}

bool Contact::isValidNumber(const std::string &str) {
	for (std::size_t i = 0; i < str.size(); ++i) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

std::string Contact::is_phonenumber(std::string info, std::string str) {
    bool valid = false;

    while (valid == false){
        std::cout << str;
        std::getline(std::cin, info);
		if (std::cin.eof())
			exit (0);
        if (std::cin.good() && !info.empty() && isValidNumber(info) == true)
            valid = true;
        else{
            std::cin.clear();
            std::cout << "❌  Phone accept only numbers. Try again." << std::endl;
        }
    }
    return (info);
}


std::string Contact::is_valid(std::string info, std::string str) {
    bool valid = false;

    while (valid == false){
        std::cout << str;
        std::getline(std::cin, info);
		if (std::cin.eof())
			exit (0);
        if (std::cin.good() && !info.empty())
            valid = true;
        else{
            std::cin.clear();
            std::cout << "❌  Invalid input. Try again." << std::endl;
        }
    }
    return (info);
}

void Contact::addInfo(int current_num){
    std::string input;

    std::cout << "Enter contact information" << std::endl;

    this->_firstName = is_valid(input, "First Name:  " );
    this->_lastName = is_valid(input, "Last Name:  " );
    this->_nickname = is_valid(input, "Nickname:  " );
    this->_phoneNumber = is_phonenumber(input, "Phone Number:  " );
    this->_darkestSecrets = is_valid(input, "Darkest Secrets:  " );
    this->_index = current_num;
    std::cout << "✅  Contact added to Phonebook!\n" << std::endl;

}

void Contact::printInfo() const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty()) {
        std::cout << "❌  No contact information available." << std::endl;
        return ;
    }
    std::cout << "-------------------------" << std::endl;
    std::cout << "|   Contact Information |" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "First Name: " << this->_firstName << std::endl;
    std::cout << "Last Name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secrets: " << this->_darkestSecrets << std::endl;
    std::cout << std::endl;
}

std::string Contact::printLen(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::showInfo() {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << this->_index;
    std::cout << "|" << std::setw(10) << this->printLen(this->_firstName);
    std::cout << "|" << std::setw(10) << this->printLen(this->_lastName );
    std::cout << "|" << std::setw(10) << this->printLen(this->_nickname );
    std::cout << "|" << std::endl;
}




// void Contact::addInfo(int current_num){
//     std::string info[5];

//     std::cout << "Enter contact information" << std::endl;

//     std::cout << "First Name:  ";
//     std::getline(std::cin, info[0]);
//     std::cout << "Last Name:  ";
//     std::getline(std::cin, info[1]);
//     std::cout << "Nickname:  ";
//     std::getline(std::cin, info[2]);
//     std::cout << "Phonenumber:  ";
//     std::getline(std::cin, info[3]);
//     std::cout << "Darkest secrets:  ";
//     std::getline(std::cin, info[4]);
//     this->_firstName = info[0];
//     this->_lastName = info[1];
//     this->_nickname = info[2];
//     this->_phoneNumber = info[3];
//     this->_darkestSecrets = info[4];
//     this->_index = current_num;

// }
