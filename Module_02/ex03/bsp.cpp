/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:34 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/10 18:02:27 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	areaCalculation(Point const up, Point const left, Point const right)
{
	return (abs((up.getX() * (left.getY() - right.getY()))
			+ (left.getX() * (right.getY() - up.getY()))
			+ (right.getX() * (up.getY() - left.getY()))) / 2);

}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

	float area_point_b_c = areaCalculation(point, b, c);
	float area_point_b_a = areaCalculation(a, point, c);
	float area_point_c_b = areaCalculation(a, b, point);
	float  area_a_b_c = areaCalculation(a, b, c);
	std::cout << "AAAAA " << a.getX() << a.getY() << std::endl;
	/*std::cout << "area_point_a_c " << area_point_a_c << std::endl;
	std::cout << "area_point_b_a " << area_point_a_c << std::endl;
	std::cout << "area_point_c_b " << area_point_a_c << std::endl;
	std::cout << "area_a_b_c " << area_point_a_c << std::endl;*/
	return (area_a_b_c == (area_point_b_c + area_point_b_a + area_point_c_b));
}
