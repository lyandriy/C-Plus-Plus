/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:06:29 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/03 18:08:36 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Base *generate(void)
{
	srand(time(NULL));
	int	i = rand() % 3;
	if (i == 0)
		return (new A());
	if (i == 1)
		return (new B());
	if (i == 2)
		return (new C());
	return (NULL);
}

void identify(Base* p)
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a != NULL)
		std::cout << "The actual type of the object pointed to by p is A." << std::endl;
	else if (b != NULL)
		std::cout << "The actual type of the object pointed to by p is B." << std::endl;
	else if (c != NULL)
		std::cout << "The actual type of the object pointed to by p is C." << std::endl;
	else
		std::cout << "The actual type of the object pointed to by p is unknown." << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "The actual type of the object pointed to by p is A." << std::endl;
		return ;
	}
	catch(std::bad_cast& e){}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "The actual type of the object pointed to by p is B." << std::endl;
		return ;
	}
	catch(std::bad_cast& e){}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "The actual type of the object pointed to by p is C." << std::endl;
		return ;
	}
	catch(std::bad_cast& e){}
	std::cout << "The actual type of the object pointed to by p is unknown." << std::endl;
}