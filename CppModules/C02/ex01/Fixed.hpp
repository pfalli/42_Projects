/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:37:05 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/30 14:21:00 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
    public:
		Fixed();
        Fixed(const int num);// --> giving fixed-point representation
		Fixed(const float num); // --> giving fixed-point representation
		Fixed(const Fixed &ex); // copy constructor
        Fixed &operator=(const Fixed &ex); // assignement operator
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

    private:
        int _value; // --> used to store the fixed-point representation
        static const int _bits = 8;

};

// overload the << operator
std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif