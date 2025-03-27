/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:15:51 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/18 10:15:51 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <unistd.h>
#include <cstdlib>

Phonebook::Phonebook(void){
    std::cout << "Costructor called" << std::endl;
}

Phonebook::~Phonebook(void){
    std::cout << "Decostructor called" << std::endl;
}

void    Phonebook::add(int current_num){
    this->_contacts[current_num % 8].addInfo((current_num % 8) + 1);
}

void    Phonebook::search(){
    show_phonebook();
    display_contact();
}

void    Phonebook::show_phonebook(){
    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
    for (int i = 0; i < 8; i++)
        this->_contacts[i].showInfo();
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << std::endl;
}

void    Phonebook::display_contact(){
    int index;
    bool flag = false;

    while(flag == false){
        std::cout << "Enter the number of the contact you want to display: ";
        std::cin >> index;
		if (std::cin.eof())
			exit (0);
        if (std::cin.fail() || index < 1 || index > 8){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "❌  Invalid input: please try again." << std::endl;
        }
        else{
            flag = true;
            std::cin.ignore(10000, '\n');
            this->_contacts[index - 1].printInfo();
        }
    }
}
