/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:13:43 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/23 15:05:26 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Constructor" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Decostructor" << std::endl;
}

void Zombie::announce( void ){
	std::cout << this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	this->_name = name;
}

bool isValidNumber(const std::string &str) {
	for (std::size_t i = 0; i < str.size(); ++i) {
	if (!std::isdigit(str[i])) {
		return false;
	}
}
	return true;
}

/*The delete operator should be used on pointers allocated with new, but in this case, 
horde is an array allocated with new[]. For this reason I use delete[] 
to deallocate the entire array */
void Zombie::deleteHorde(Zombie *horde) {
	delete[] horde;
}
