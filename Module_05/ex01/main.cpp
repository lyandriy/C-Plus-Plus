/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:22:36 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/31 12:34:06 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		//Bureaucrat bob;
		Bureaucrat bob(120, "bob");
		//Bureaucrat bob(0, "bob");
		//Bureaucrat bob(170, "bob");
		Form a("form", 121, 20);
		bob.signForm(a);
		std::cout << bob << std::endl;
		std::cout << a << std::endl;
		std::cout << bob.getGrade() << std::endl;
		bob.dGrade();
		std::cout << bob.getGrade() << std::endl;
		bob.iGrade();
		std::cout << bob.getGrade() << std::endl;
		std::cout << bob.getName() << a.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
