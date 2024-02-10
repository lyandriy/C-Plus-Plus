/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:48 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/10 17:52:04 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void){
	y.setRawBits(0);
	x.setRawBits(0);
}

Point::~Point(void){}

Point &Point::operator=(const Point &other)
{
	this->setX(other.getX());
	this->setY(other.getY());
	return (*this);
}

Point::Point(Fixed _x, Fixed _y){
	this->x.setRawBits(_x.getRawBits());
	this->y.setRawBits(_y.getRawBits());
}

Point::Point(const Point &other){
	*this = other;
}

int	Point::getX(void) const
{
	return (this->x.getRawBits());
}

int	Point::getY(void) const
{
	return (this->y.getRawBits());
}

void	Point::setX(int const raw)
{
	this->x.setRawBits(raw);
}

void	Point::setY(int const raw)
{
	this->y.setRawBits(raw);
}