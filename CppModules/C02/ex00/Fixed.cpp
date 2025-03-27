/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:38:44 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/28 13:26:03 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const Fixed& ex) : _fixedPoint(ex._fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

/* The assignment operator is used to copy the value from
	one object to another, and it is implemented by overloading the
	assignment operator (=).*/
Fixed &Fixed::operator=(const Fixed &ex)// assignment operator
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPoint = ex._fixedPoint;
	return (*this);
}