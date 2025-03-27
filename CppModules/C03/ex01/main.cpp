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

int main( void ) {
	ScavTrap Marta("Marta");
	ScavTrap Roberta("Roberta");
	Marta.showInfo();
	Roberta.showInfo();
	Marta.attack("Roberta");
	Roberta.takeDamage(2);
	Marta.guardGate();
	Roberta.attack("Marta");
	Marta.takeDamage(5);
	Marta.beRepaired(10);
	Marta.showInfo();
	Roberta.showInfo();
}