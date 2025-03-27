/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:12:46 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/23 15:14:01 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(){
	std::string name;
	std::cout << "give name of Zombie1: ";
	std::cin >> name;

	Zombie zombie;
	zombie.setName(name);
	zombie.announce();

	std::cout << "give name of newZombie(HEAP): ";
	std::cin >> name;

	Zombie *zombie2 = newZombie(name);
	zombie2->announce();

	std::cout << "give name of randomChump(STACK): ";
	std::cin >> name;

	randomChump(name);

	delete zombie2;
	return 0;
}
