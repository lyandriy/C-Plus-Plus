/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:37:28 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/21 09:58:25 by lyandriy         ###   ########.fr       */
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

int main()
{
const Animal* meta = new Animal[100];
for (int i = 0; i < 50; i++)
	meta[i] = 
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;
return 0;
}
