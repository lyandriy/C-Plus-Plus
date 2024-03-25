/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:22 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/25 19:05:38 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "stdlib.h"

int main()
{
	std::cout << "************ RobotomyRequestForm\n";
	try
	{
		Bureaucrat marlyn(10, "marlyn");
		RobotomyRequestForm a("Form_marlyn");
		marlyn.executeForm(a);
		marlyn.signForm(a);
		marlyn.executeForm(a);
		marlyn.executeForm(a);
		marlyn.executeForm(a);
		marlyn.executeForm(a);
		marlyn.executeForm(a);
		Bureaucrat bob;
		RobotomyRequestForm b("Form_marlyn");
		bob.signForm(b);
		bob.executeForm(b);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "************ PresidentialPardonForm\n";
	try
	{
		Bureaucrat marlyn(10, "marlyn");
		PresidentialPardonForm a("Form_marlyn");
		marlyn.executeForm(a);
		marlyn.signForm(a);
		marlyn.executeForm(a);
		Bureaucrat bob;
		RobotomyRequestForm b("Form_marlyn");
		bob.signForm(b);
		bob.executeForm(b);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "************ ShrubberyCreationForm\n";
	try
	{
		Bureaucrat marlyn(10, "marlyn");
		ShrubberyCreationForm a("Form_marlyn");
		marlyn.executeForm(a);
		marlyn.signForm(a);
		marlyn.executeForm(a);
		Bureaucrat bob;
		RobotomyRequestForm b("Form_marlyn");
		bob.signForm(b);
		bob.executeForm(b);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}