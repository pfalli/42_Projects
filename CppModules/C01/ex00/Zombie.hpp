/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:06:39 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/23 13:55:12 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdio>

class Zombie{
	private:
		std::string _name;

    public:
		Zombie();
		~Zombie();
		void setName(std::string name);
		void announce( void );
		Zombie* newZombie( std::string name );
		void	randomChump( std::string name );
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif