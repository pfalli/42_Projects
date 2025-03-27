/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:36:32 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/30 14:25:30 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/* this project is about creating some member fucntions 
that inside the costructors will convert the INT ot FLOAT or opposite*/

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f ); // copy assignment operator here
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << std::endl;

	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(256);
	std::cout << a.getRawBits() << std::endl;
	std::cout << "a is "<< a << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << std::endl;

	a = Fixed( 1234.4321f );
	std::cout << a.getRawBits() << std::endl;
	std::cout << "a is "<< a << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;

	return 0;
}
