/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:37:28 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/09 17:21:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog basic;
	{

		basic.set_("hola");
		basic.set_("hola1");
		std::cout << basic.getIdea(0) << std::endl;
		std::cout << basic.getIdea(1) << std::endl;
		std::cout << basic.getIdea(2) << std::endl;
		Dog tmp = basic;
		tmp.set_("hola20");
		std::cout << "hola0000000\n";
		std::cout << tmp.getIdea(0) << std::endl;
		std::cout << tmp.getIdea(1) << std::endl;
		std::cout << tmp.getIdea(2) << std::endl;
		std::cout << basic.getIdea(4) << std::endl;

	}
	Animal* meta[4];
	for (int i = 0; i < 2; i++)
		meta[i] = new Dog();
	for (int i = 2; i < 4; i++)
		meta[i] = new Cat();
	for (int i = 0; i < 4; i++)
		std::cout << meta[i]->getType() << std::endl;
	for (int i = 0; i < 4; i++)
		meta[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete meta[i];
	return 0;
}
