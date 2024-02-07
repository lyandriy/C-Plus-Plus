/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:02 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/07 19:46:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fract_bits = 8;

/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/

Fixed::Fixed(void) : fixed_point(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

/*---CONSTRUCTORS---*/

Fixed::Fixed(const int parameter){
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = parameter << this->fract_bits;
}

Fixed::Fixed(const float number){
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = std::roundf(number * (1 << this->fract_bits));
}

/*---GETER/SETER---*/

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

/*---FLOAT/INT---*/

float	Fixed::toFloat(void) const {
	std::cout << "float	Fixed::toFloat" << std::endl;
	float i = static_cast<float>(this->fixed_point) / static_cast<float>(1 << this->fract_bits);
	return i;
}

int	Fixed::toInt(void) const {
	std::cout << "int	Fixed::toInt" << std::endl;
	return (this->fixed_point >> this->fract_bits);
}

/*---COMPARISON OPERATORS---*/

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->fixed_point < other.fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->fixed_point > other.fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->fixed_point <= other.fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->fixed_point >= other.fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->fixed_point != other.fixed_point)
		return (true);
	return (false);
}


/*---ARITHMETIC OPERATORS---*/

Fixed	Fixed::operator+(const Fixed &other)
{
	this->fixed_point += other.fixed_point;
	return (*this);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	this->fixed_point -= other.fixed_point;
	return (*this);
}

Fixed	Fixed::operator*(const Fixed &other)
{
	this->fixed_point *= other.fixed_point;
	return (*this);
}

Fixed	Fixed::operator/(const Fixed &other)
{
	this->fixed_point /= other.fixed_point;
	return (*this);
}

/*--INCREMENT/DECREMENT---*/
Fixed	Fixed::operator++()
{
	std::cout << "const Fixed	&Fixed::operator++" << std::endl;
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator++(int number)
{
	//Fixed	copy(*this);
	std::cout << "const Fixed	&Fixed::operator++(int)" << number << std::endl;
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator--(int number)
{
	this->fixed_point -= number;
	return (*this);
}

/*---MIN/MAX---*/

Fixed	&Fixed::min(Fixed &ref_1, Fixed &ref_2)
{
	std::cout << "Fixed	&Fixed::min" << std::endl;
	if (ref_1.fixed_point < ref_2.fixed_point)
		return (ref_1);
	return (ref_2);
}

Fixed	&Fixed::max(Fixed &ref_1, Fixed &ref_2)
{
	std::cout << "Fixed	&Fixed::max" << std::endl;
	if (ref_1.fixed_point > ref_2.fixed_point)
		return (ref_1);
	return (ref_2);
}

const Fixed	&Fixed::min(const Fixed &ref_1, const Fixed &ref_2)
{
	std::cout << "const Fixed	&Fixed::min" << std::endl;
	if (ref_1.fixed_point < ref_2.fixed_point)
		return (ref_1);
	return (ref_2);
}

const Fixed	&Fixed::max(const Fixed &ref_1, const Fixed &ref_2)
{
	std::cout << "const Fixed	&Fixed::max" << std::endl;
	if (ref_1.fixed_point > ref_2.fixed_point)
		return (ref_1);
	return (ref_2);
}


/*---COPY ASSIGNMENT---*/

std::ostream &operator<<(std::ostream& oso, const Fixed& fixed)
{
	oso << fixed.toFloat();
	return (oso);
}

/*---------------------------------------------------------------------*/
