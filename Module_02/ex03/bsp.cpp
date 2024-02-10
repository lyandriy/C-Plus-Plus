/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:34 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/10 19:18:40 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	areaCalculation(Point const up, Point const left, Point const right)
{
	return (std::abs((up.getX() * (left.getY() - right.getY()))
			+ (left.getX() * (right.getY() - up.getY()))
			+ (right.getX() * (up.getY() - left.getY()))) / 2);

}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

	int area_point_b_c = areaCalculation(point, b, c);
	int area_point_b_a = areaCalculation(a, point, c);
	int area_point_c_b = areaCalculation(a, b, point);
	int area_a_b_c = areaCalculation(a, b, c);
	if (area_point_b_c == 0 || area_point_b_a == 0 || area_point_c_b == 0)
		return (false);
	return ((area_a_b_c == (area_point_b_c + area_point_b_a + area_point_c_b)));
}
