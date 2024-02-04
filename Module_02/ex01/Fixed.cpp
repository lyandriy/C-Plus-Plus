/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:02 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/04 16:56:38 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fract_bits = 8;

Fixed::Fixed(void) : fixed_point(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

/*---------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------*/

Fixed::Fixed(const int parameter){
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = parameter << this->fract_bits;
}

Fixed::Fixed(const float number){
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = std::roundf(number * (1 << this->fract_bits));
}

/*---------------------------------------------------------------------*/

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

/*---------------------------------------------------------------------*/

float	Fixed::toFloat(void) const {
	float i = static_cast<float>(this->fixed_point) / static_cast<float>(1 << this->fract_bits);
	return i;
}

int	Fixed::toInt(void) const {
	return (this->fixed_point >> this->fract_bits);
}

/*---------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& oso, const Fixed& fixed)
{
	oso << fixed.toFloat();
	return (oso);
}
