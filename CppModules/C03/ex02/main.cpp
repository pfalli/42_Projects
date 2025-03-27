/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:36:32 by pfalli            #+#    #+#             */
/*   Updated: 2024/11/02 14:29:09 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	FragTrap Tody("Tody");
	FragTrap Jack("Jack");
	Tody.showInfo();
	Jack.showInfo();
	Tody.attack("Jack");
	Jack.takeDamage(2);
	Tody.highFivesGuys();
	Jack.attack("Tody");
	Tody.takeDamage(5);
	Tody.beRepaired(10);
	Tody.showInfo();
	Jack.showInfo();
	Tody.highFivesGuys();
	Jack.highFivesGuys();
}