/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:37:05 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/30 12:40:48 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <string>

class Fixed{
    public:
        Fixed(); // initialize a class
        Fixed(const Fixed &ex); // initialize a copy of a class
        Fixed &operator=(const Fixed &ex); // assignement operator
        ~Fixed(); // deconstructor

        int getRawBits( void ) const; // getter
        void setRawBits( int const raw ); // setter

    private:
        int _fixedPoint; // fixed point number
        static const int _fractionalBits = 8;

};

#endif