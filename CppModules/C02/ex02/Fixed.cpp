/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:38:44 by pfalli            #+#    #+#             */
/*   Updated: 2024/11/02 14:25:44 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//---------------------------------------------------------
//-                   CONSTRUCTORS                        -
//---------------------------------------------------------

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int num){
	// std::cout << "Int constructor called" << std::endl;
	this->_value = num << _bits;; // to convert the integer value to a fixed-point representation.
}

Fixed::Fixed(const float num){
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << _bits)); // to convert the float value to a fixed-point representation.
}

Fixed::Fixed(const Fixed& ex) : _value(ex._value)
{
	// std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &ex)// assignment operator
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ex) { // Check for self-assignment: This checks if the current object is not the same as the object being assigned.
		this->_value = ex._value;
	}
	return (*this); // This allows the assignment operator to be used in a chain of assignments.
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

//---------------------------------------------------------
//-                   FUNCTIONS                           -
//---------------------------------------------------------

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called -->"<< raw << std::endl;
	this->_value = raw;
}

float Fixed::toFloat()const
{
	float val = this->_value;
	int end = 1 << _bits;
	val = val / end;
	return(val);
}

int Fixed::toInt()const
{
	int val = this->_value;

	int intVal = val >> _bits;
	return(intVal);
}

/*  allowing custom objects to be printed directly using std::cout or other output streams
 With this overload, you can directly use std::cout << v1 to print a Vector object */
std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
    os << other.toFloat();
    return(os);
}

//---------------------------------------------------------
//-              OPERATORS OVERLOAD                       -
//---------------------------------------------------------


bool Fixed::operator<(const Fixed &other) const {
	if (this->_value < other._value)
		return true;
	return false;
}

bool Fixed::operator>(const Fixed &other) const {
	if (this->_value < other._value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other) const {
	if (this->_value >= other._value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other) const {
	if (this->_value <= other._value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other) const {
	if (this->_value == other._value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other) const {
	if (this->_value != other._value)
		return true;
	return false;
}

//---------------------------------------------------------

Fixed Fixed::operator+(const Fixed &num) const
{
	Fixed result;
	result = this->toFloat() + num.toFloat();
	return(result);
}

Fixed Fixed::operator*(const Fixed &num) const
{
	Fixed result;
	result = this->toFloat() * num.toFloat();
	return(result);
}

Fixed Fixed::operator-(const Fixed &num) const
{
	Fixed result;
	result = this->toFloat() - num.toFloat();
	return(result);
}

Fixed Fixed::operator/(const Fixed &num) const
{
	Fixed result;
	result = this->toFloat() / num.toFloat();
	return(result);
}

//---------------------------------------------------------------

Fixed Fixed::operator++()
{
	this->_value++;
	return(*this);
}

Fixed Fixed::operator--()
{
	this->_value--;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed answer(*this);
	++this->_value;
	return(answer);
}

Fixed Fixed::operator--(int)
{
	Fixed answer(*this);
	--this->_value;
	return(answer);
}

//---------------------------------------------------------
//-           OVERLOAD MEMBER FUNCTIONS                   -
//---------------------------------------------------------

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}