/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/09 19:54:02 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.cpp"

class	Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point(void);
		~Point();

		Point(const float numb_1, const float numb_2);
		Point(const Point &other);
};

#endif