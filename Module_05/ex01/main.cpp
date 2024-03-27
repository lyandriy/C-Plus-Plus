/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:22:36 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/27 17:42:31 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat *new_bob = new Bureaucrat(120, "new_bob");
		Bureaucrat other_bob = *new_bob;
		Form a("hola", 10, 20);
		new_bob->signForm(a);
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
		Form a("hola", 10, 20);
		bob->signForm(a);
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
		Form a("hola", 10, 20);
		bob->signForm(a);
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
		Form a("hola", 10, 20);
		bob->signForm(a);
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
