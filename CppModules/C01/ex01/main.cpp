/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:12:46 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/23 15:05:30 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	int number;
	std::string name;

	std::cout << "Write number of zombies: " << std::endl;
	std::string numberStr;
	std::cin >> numberStr;
	if (isValidNumber(numberStr)) {
		number = atoi(numberStr.c_str());
	} else {
		std::cout << "Invalid input. Please enter a valid number." << std::endl;
		return 1;
	}
	std::cout << "Enter the name for the zombies: " << std::endl;
	std::cin >> name;
	
	Zombie *horde = NULL;
	horde = horde->zombieHorde(number, name);
	horde->deleteHorde(horde);
	
	
	return 0;
}
