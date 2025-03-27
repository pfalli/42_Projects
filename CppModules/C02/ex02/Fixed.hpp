/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:37:05 by pfalli            #+#    #+#             */
/*   Updated: 2024/11/02 11:04:26 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{

	private:
		int _value; // --> used to store the fixed-point representation
		static const int _bits = 8;

    public:
		Fixed();
        Fixed(const int num);// --> giving fixed-point representation
		Fixed(const float num); // --> giving fixed-point representation
		Fixed(const Fixed &ex); // copy constructor
        Fixed &operator=(const Fixed &ex); // assignement operator
        ~Fixed();

		// fixed point number
        int getRawBits( void ) const;
        void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		
		// operators
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// increment and decrement operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		// overload member function
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif