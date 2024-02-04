/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:46:41 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/02 18:13:44 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "The memory address of the string variable " << &brain << std::endl;
	std::cout << "The memory address held by stringPTR " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF " << &stringREF << std::endl << std::endl;

	std::cout << "The value of the string variable " << brain << std::endl;
	std::cout << "The value pointed to by stringPTR " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF " << stringREF << std::endl;
	return (0);
}
