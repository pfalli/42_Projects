/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:36:32 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/28 16:21:07 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* this project is a demostartion of how to create "fixed classes"
 that we declare already inside the constructors*/

int main( void ) {
    Fixed a;
	// a.setRawBits(42);
    Fixed b( a );
    Fixed c;

    c = b; // copying assignment operator

	// a.setRawBits(42);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    // a.setRawBits(100);
    // b.setRawBits(-42);
    // c.setRawBits(5);
    // std::cout << a.getRawBits() << std::endl;
    // std::cout << b.getRawBits() << std::endl;
    // std::cout << c.getRawBits() << std::endl;
    return 0;
}

