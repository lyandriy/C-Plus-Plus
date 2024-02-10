/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/10 17:31:40 by lyandriy         ###   ########.fr       */
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
		Point(Fixed _x, Fixed _y);
		Point(const Point &other);

		int	getX(void) const;
		int	getY(void) const;

		void	setX(int const raw);
		void	setY(int const raw);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif