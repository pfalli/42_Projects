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

int main( void ) {
	ClapTrap Piero("Piero");
	ClapTrap Cesare("Cesare");
	Piero.showInfo();
	Cesare.showInfo();
	Piero.attack("Cesare");
	Cesare.takeDamage(2);
	Cesare.attack("Piero");
	Piero.takeDamage(5);
	Piero.showInfo();
	Cesare.showInfo();
	Piero.beRepaired(10);
	Piero.beRepaired(10);
	Piero.showInfo();
	Cesare.showInfo();
}