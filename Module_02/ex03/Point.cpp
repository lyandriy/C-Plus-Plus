/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:48 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/11 19:21:48 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void) : x(0), y(0){
}

Point::~Point(void){}

Point &Point::operator=(const Point &other)
{
	this->x.setRawBits(other.getX());
	this->y.setRawBits(other.getY());
	return (*this);
}

Point::Point(float _x, float _y): x(_x), y(_y){}

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
