/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:06:39 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/23 15:05:37 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

class Zombie{
	private:
		std::string _name;

    public:
		Zombie();
		~Zombie();
		void setName(std::string name);
		void announce( void );
		Zombie* zombieHorde( int N, std::string name );
		void deleteHorde(Zombie *horde);
};

bool isValidNumber(const std::string &str);

#endif