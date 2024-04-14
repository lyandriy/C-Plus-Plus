/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:45:30 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/14 16:10:00 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : size(0), pos(0) {}

Span::~Span(){}

Span::Span(const Span &other)
{
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	for (size_t i = 0; i < other.vec.size(); i++)
		this->vec.push_back(other.vec[i]);
	this->size = other.size;
	this->pos = other.pos;
	return (*this);
}

Span::Span(unsigned int N) : size(N), pos(0), vec(N) {}

void	Span::addNumber(int Numb)
{
	if (pos < size)
	{
		vec[pos] = Numb;
		pos++;
	}
	else
		throw std::exception();
}

void	Span::iterator(std::vector<int> _c_vec)
{
	for (size_t i = 0; (i < vec.size() && i < _c_vec.size()); i++)
	{
		vec[i] = _c_vec[i];
		this->pos++;
	}
}

void	Span::iterator(int *array, size_t size)
{
	for (size_t i = 0; (i < vec.size() && i < size); i++)
	{
		vec[i] = array[i];
		this->pos++;
	}
}

int	Span::shortestSpan()
{
	int	dif = vec[0] - vec[1];
	int a = 0;
	if (dif < 0)
		dif *= -1;

	for (int i = 0; i < pos; i++)
	{
		for (int j = 0; j < pos; j++)
		{
			a = this->vec[i] - this->vec[j];
			if (a < 0)
				a *= -1;
			if (a < dif && a != 0)
				dif = a;
		}
	}
	return (dif);
}

int	Span::longestSpan()
{
	int	dif = 0;

	for (int i = 0; i < this->pos; i++)
	{
		for (int j = 0; j < this->pos; j++)
		{
			if ((this->vec[i] - this->vec[j]) > dif)
				dif = this->vec[i] - this->vec[j];
		}
	}
	return (dif);
}
