/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:22 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/31 13:00:10 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "stdlib.h"

int main()
{
	try
	{
		Bureaucrat bob(10, "bob");
		Intern	boby;
		std::cout << "-------------------------\n";
		AForm *interno = boby.makeForm("presidential pardon", "Bender");
		bob.signForm(*interno);
		bob.executeForm(*interno);
		delete interno;
		std::cout << "-------------------------\n";
		interno = boby.makeForm("robotomy request", "Bender");
		bob.signForm(*interno);
		bob.executeForm(*interno);
		delete interno;
		std::cout << "-------------------------\n";
		interno = boby.makeForm("shrubbery creation", "Bender");
		bob.signForm(*interno);
		bob.executeForm(*interno);
		delete interno;
		std::cout << "-------------------------\n";
		interno = boby.makeForm("patata", "Bender");
		bob.signForm(*interno);
		bob.executeForm(*interno);
		delete interno;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}