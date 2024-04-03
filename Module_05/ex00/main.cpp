/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:22:36 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/31 19:10:57 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob;
		//Bureaucrat bob(120, "bob");
		//Bureaucrat bob(0, "bob");
		//Bureaucrat bob(170, "bob");
		std::cout << bob.getGrade() << std::endl;
		bob.dGrade();
		std::cout << bob.getGrade() << std::endl;
		bob.iGrade();
		std::cout << bob.getGrade() << std::endl;
		std::cout << bob.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
