/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:57:11 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/10 16:32:58 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		T	*a;
		unsigned int	array_size;
	public:
		Array()
		{
			this->a = NULL;
			this->array_size = 0;
		};
		~Array()
		{
			delete[] this->a;
		};
		Array(const Array &other) : a(new T[other.array_size]()), array_size(other.array_size)
		{
			for (unsigned int i = 0; i < other.array_size; i++)
				this->a[i] = other.a[i];
		};
		Array	&operator=(const Array& other)
		{
			if (this == &other)
				return (*this);
			if (this->a)
				delete[] this->a;
			this->a = new T[other.array_size]();
			for (unsigned int i = 0; i < other.array_size; i++)
				this->a[i] = other.a[i];
			this->array_size = other.array_size;
			return (*this);
		};
		T	&operator[](unsigned int pos)
		{
			if (pos >= this->array_size)
				throw std::exception();
			return (this->a[pos]);
		};
		const T	&operator[](unsigned int pos) const
		{
			if (pos >= this->array_size)
				throw std::exception();
			return (this->a[pos]);
		};
		Array(unsigned int n)
		{
			this->a = new T[n]();
			this->array_size = n;
		};
		unsigned int	size()
		{
			return (this->array_size);
		};
};

#endif