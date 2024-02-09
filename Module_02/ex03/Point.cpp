/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:48 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/09 19:57:02 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.cpp"

Point::Point(void) : x.setRawBits(0), y.setRawBits(0){}

Point::~Point(void){}

Point::Point(const float numb_1, const float numb_2){
	this->x.setRawBits(numb_1);
	this->y.setRawBits(numb_2);
}

Point::Point(const Point &other){
	*this = other;
}

Point &Point::operator=(const Point &other)
{
	this->setRawBits(other.getRawBits());
	return (*this);
}