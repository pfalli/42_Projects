/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:59:09 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/18 10:59:09 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <unistd.h>
#include <iostream>
#include <cstdlib>

int main(){

    Phonebook book;
    std::string info[5];
    std::string input;
    int current_num = 0;

    std::cout << "☎️   Welcome to your Phonebook" << std::endl;
    while (1){
        std::cout << GREEN "Wanna ADD, SEARCH or EXIT?" RESET << std::endl;
        std::getline(std::cin, input);
		if (std::cin.eof())
			exit (0);
        if (input.compare("EXIT") == 0){
            std::cout << "Bye, have a nice day!" << std::endl;
            sleep(2);
            break;
        }
        else if (input.compare("ADD") == 0){
            book.add(current_num);
            current_num++;
        }
        else if (input.compare("SEARCH") == 0){
            book.search();
        }

    }
    return 0;
}