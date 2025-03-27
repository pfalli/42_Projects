/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:13:43 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/23 15:10:29 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    // std::cout << "Constructor" << std::endl;
}

Zombie::~Zombie() {
    // std::cout << "Decostructor" << std::endl;
	std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce( void ){
    std::cout << this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	this->_name = name;
}


