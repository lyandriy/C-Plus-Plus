/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:05 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/04 15:16:34 by lyandriy         ###   ########.fr       */
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
		Fixed(void);
		~Fixed();

		Fixed(const Fixed &other);
		Fixed &operator= (const Fixed &other);

		Fixed(const int parameter);
		Fixed(const float number);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& oso, const Fixed& fixed);


#endif
