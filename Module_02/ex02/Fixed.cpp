/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:02 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/11 19:19:32 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fract_bits = 8;

/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/

Fixed::Fixed(void) : fixed_point(0){}

Fixed::~Fixed(){}

/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	return (*this);
}

/*---CONSTRUCTORS---*/

Fixed::Fixed(const int parameter){
	this->fixed_point = parameter << this->fract_bits;
}

Fixed::Fixed(const float number){
	this->fixed_point = roundf(number * (1 << this->fract_bits));
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
	float i = static_cast<float>(this->fixed_point) / static_cast<float>(1 << this->fract_bits);
	return i;
}

int	Fixed::toInt(void) const {
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

bool	Fixed::operator==(const Fixed &other) const
{
	if (this->fixed_point == other.fixed_point)
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
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

/*--INCREMENT/DECREMENT---*/
Fixed	Fixed::operator++()
{
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);
	this->fixed_point++;
	return (copy);
}

Fixed	Fixed::operator--()
{
	this->fixed_point--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);
	this->fixed_point--;
	return (copy);
}

/*---MIN/MAX---*/

Fixed	&Fixed::min(Fixed &ref_1, Fixed &ref_2)
{
	if (ref_1.fixed_point < ref_2.fixed_point)
		return (ref_1);
	return (ref_2);
}

Fixed	&Fixed::max(Fixed &ref_1, Fixed &ref_2)
{
	if (ref_1.fixed_point > ref_2.fixed_point)
		return (ref_1);
	return (ref_2);
}

const Fixed	&Fixed::min(const Fixed &ref_1, const Fixed &ref_2)
{
	if (ref_1.fixed_point < ref_2.fixed_point)
		return (ref_1);
	return (ref_2);
}

const Fixed	&Fixed::max(const Fixed &ref_1, const Fixed &ref_2)
{
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
