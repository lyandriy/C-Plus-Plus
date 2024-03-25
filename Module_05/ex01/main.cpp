/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:22:36 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/24 18:53:46 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void seeleaks()
{
	system("leaks -q Bureaucrat");
}

int main(void)
{
	atexit(&seeleaks);
	try
	{
		Bureaucrat bob;
		/*Bureaucrat other_bob = bob;
		std::cout << other_bob.getName() << std::endl;
		std::cout << bob << std::endl;*/
		Bureaucrat *new_bob = new Bureaucrat(120, "new_bob");
		Bureaucrat other_bob = *new_bob;
		std::cout << other_bob.getName() << std::endl;
		std::cout << other_bob << std::endl;
		new_bob->iGrade();
		std::cout << new_bob->getGrade() << std::endl;
		std::cout << new_bob->getName() << std::endl;
		std::cout << *new_bob << std::endl;
		new_bob->iGrade();
		std::cout << new_bob->getGrade() << std::endl;
		delete new_bob;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *bob = new Bureaucrat(120, "bob");
		bob->dGrade();
		std::cout << bob->getGrade() << std::endl;
		std::cout << bob->getName() << std::endl;
		std::cout << *bob << std::endl;
		bob->dGrade();
		std::cout << bob->getGrade() << std::endl;
		delete bob;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *bob = new Bureaucrat(170, "bob");
		bob->dGrade();
		bob->dGrade();
		std::cout << bob->getGrade() << std::endl;
		delete bob;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *bob = new Bureaucrat(0, "bob");
		bob->dGrade();
		bob->dGrade();
		std::cout << bob->getGrade() << std::endl;
		delete bob;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
