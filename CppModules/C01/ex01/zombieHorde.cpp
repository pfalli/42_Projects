/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:46:29 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/23 14:44:59 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name ) {
	Zombie *horde;

	horde= new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
		horde[i].announce();
	}
	return(horde);
}