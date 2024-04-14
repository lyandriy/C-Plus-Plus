/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:34:20 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/14 19:00:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator	iterator;
		typedef typename std::deque<T>::reverse_iterator	reverse_iterator;
		typedef typename std::deque<T>::const_iterator	const_iterator;
		typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;

		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack &other)
		{
			*this = other;
		}
		MutantStack	&operator=(const MutantStack &other)
		{
			this->c = other.c;
			return (*this);
		}

		iterator	begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{
			return (this->c.rend());
		}
		const_iterator	begin() const
		{
			return (this->c.begin());
		}
		const_iterator end() const
		{
			return (this->c.end());
		}
		const_reverse_iterator rbegin() const
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const
		{
			return (this->c.rend());
		}
};
