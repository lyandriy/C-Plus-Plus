/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:45:21 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/03 18:09:34 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int	main()
{
	Base	*new_base = generate();
	identify(*new_base);
	identify(new_base);
	delete new_base;
	std::cout << "-----------------------------------\n";
	Base	*b = new B();
	identify(*b);
	identify(b);
	delete b;
	std::cout << "-----------------------------------\n";
	Base	*c = new C();
	identify(*c);
	identify(c);
	delete c;
	std::cout << "-----------------------------------\n";
	Base	*a = new A();
	identify(*a);
	identify(a);
	delete a;
	return (0);
}