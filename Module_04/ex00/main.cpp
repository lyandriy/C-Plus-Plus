/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:37:28 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/06 15:57:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "stdlib.h"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const WrongAnimal *WrongMeta = new WrongAnimal();
	const WrongAnimal *_j = new WrongCat();
	const WrongCat *g = new WrongCat();
	g->makeSound();
	std::cout << WrongMeta->getType() << std::endl;
	std::cout << _j->getType() << std::endl;
	WrongMeta->makeSound();
	_j->makeSound();
	delete g;
	delete WrongMeta;
	delete _j;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}
