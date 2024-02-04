/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:05 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/03 19:10:06 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif