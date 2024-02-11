/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/11 19:16:54 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class	Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point(void);
		~Point();

		Point &operator=(const Point &other);
		Point(float _x, float _y);
		Point(const Point &other);

		int	getX(void) const;
		int	getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif