/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:39 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/11 19:20:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed_point;
		static const int	fract_bits;
	public:
	/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/
		Fixed(void);
		~Fixed();

	/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &other);

	/*---CONSTRUCTORS---*/
		Fixed(const int parameter);
		Fixed(const float number);

	/*---GETER/SETER---*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	/*---FLOAT/INT---*/
		float	toFloat(void) const;
		int		toInt(void) const;

	/*---COMPARISON OPERATORS---*/
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator<=(const Fixed &other)const;
		bool	operator>=(const Fixed &other)const;
		bool	operator==(const Fixed &other)const;
		bool	operator!=(const Fixed &other)const;

	/*---ARITHMETIC OPERATORS---*/
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);

	/*--INCREMENT/DECREMENT---*/
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

	/*---MIN/MAX---*/
		static Fixed		&min(Fixed &ref_1, Fixed &ref_2);
		static Fixed		&max(Fixed &ref_1, Fixed &ref_2);
		static const Fixed	&min(const Fixed &ref_1, const Fixed &ref_2);
		static const Fixed	&max(const Fixed &ref_1, const Fixed &ref_2);
};

#endif