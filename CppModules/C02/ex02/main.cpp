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

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << "--> value" << std::endl;
	std::cout << ++a << "--> pre-increment" << std::endl;
	std::cout << a << "--> value" << std::endl;
	std::cout << a++ << "--> post-increment" <<std::endl;
	std::cout << a << "--> value" <<  std::endl;
	
	std::cout << b << "--> moltiplication *" << std::endl;

	if(a < b)
		std::cout <<  "< operator "  << a << std::endl;
	else
		std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}