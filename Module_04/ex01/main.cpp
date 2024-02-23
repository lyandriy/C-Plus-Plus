/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:37:28 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 19:19:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

/*int	main(void)
{
	Cat	Michi;
	Dog	Firulais;

	Michi.makeSound();
	Firulais.makeSound();
	return (0);
}*/

void seeleaks()
{

	system("leaks -q Animal");
}

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
	for (int i = 0; i < 2; i++)
		delete meta[i];
	for (int i = 2; i < 4; i++)
		delete meta[i];
	atexit(&seeleaks);
	return 0;
}
