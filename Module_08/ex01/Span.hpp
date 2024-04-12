/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:45:33 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/12 19:14:53 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>

class Span
{
	private:
		int	size;
		int	pos;
		std::vector<int> vec;
	public:
		Span();
		~Span();

		Span(const Span &other);
		Span	&operator=(const Span &other);
		Span(unsigned int N);

		void	addNumber(int Numb);
		void	iterator(std::vector<int> _c_vec);
		void	iterator(int *array, size_t size);
		int		shortestSpan();
		int		longestSpan();
};

#endif