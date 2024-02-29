/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:37:28 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/29 17:50:13 by lyandriy         ###   ########.fr       */
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
	Animal *A = new Dog();
	A->makeSound();
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
	for (int i = 0; i < 2; i++)
		delete meta[i];
	for (int i = 2; i < 4; i++)
		delete meta[i];
	delete A;
	//atexit(&seeleaks);
	return 0;
}
