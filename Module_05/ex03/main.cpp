/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:22 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/27 16:20:44 by lyandriy         ###   ########.fr       */
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
		Bureaucrat bob;
		Bureaucrat marlyn(10, "marlyn");
		RobotomyRequestForm a("Mmmm");
		marlyn.signForm(a);
		marlyn.executeForm(a);
		Intern	boby;
		AForm *interno = boby.makeForm("presidential pardon", "Bender");
		marlyn.signForm(*interno);
		marlyn.executeForm(*interno);
		delete interno;
		interno = boby.makeForm("robotomy request", "Bender");
		marlyn.executeForm(*interno);
		delete interno;
		interno = boby.makeForm("shrubbery creation", "Bender");
		marlyn.executeForm(*interno);
		delete interno;
		interno = boby.makeForm("patata", "Bender");
		marlyn.executeForm(*interno);
		delete interno;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}