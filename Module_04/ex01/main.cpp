/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:37:28 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/29 17:49:02 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

/*void seeleaks()
{
	system("leaks -q Animal");
}*/

int main()
{
	Animal* meta[4];
	for (int i = 0; i < 2; i++)
		meta[i] = new Dog();
	for (int i = 2; i < 4; i++)
		meta[i] = new Cat();
	for (int i = 0; i < 2; i++)
		std::cout << meta[i]->getType() << " " << std::endl;
	for (int i = 2; i < 4; i++)
		std::cout << meta[i]->getType() << " " << std::endl;
	for (int i = 0; i < 2; i++)
		meta[i]->makeSound();
	for (int i = 2; i < 4; i++)
		meta[i]->makeSound();
	/*meta[0]->set_("hola");
	meta[0]->set_("hola1");
	meta[0]->set_("hola2");
	meta[0]->set_("hola3");
	std::cout << meta[0]->getIdea(0) << std::endl;
	std::cout << meta[0]->getIdea(1) << std::endl;
	std::cout << meta[0]->getIdea(2) << std::endl;
	std::cout << meta[0]->getIdea(3) << std::endl;
	std::cout << meta[0]->getIdea(4) << std::endl;*/
	for (int i = 0; i < 2; i++)
		delete meta[i];
	for (int i = 2; i < 4; i++)
		delete meta[i];
	//atexit(&seeleaks);
	return 0;
}
