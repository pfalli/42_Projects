/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:07:48 by pfalli            #+#    #+#             */
/*   Updated: 2024/11/25 18:47:18 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>
#include <string>

int main() {
    Harl person; // object
    std::string level;
    std::cout << "Type one of the level (DEBUG, INFO, WARNING, ERROR): ";
    std::getline(std::cin, level);
    if (level.empty()) {
        std::cout << "Input is empty." << std::endl;
		return 0;
    }
    person.complain(level);
}