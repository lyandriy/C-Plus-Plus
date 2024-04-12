/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:57:04 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/10 16:30:58 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void seeleaks()
{
	system("leaks -q array");
}

int main()
{
	atexit(&seeleaks);
	Array<std::string> str(1);
	str[0] = "hola";
	std::cout << "soy str: " << str[0] << std::endl;

	Array<std::string> str_2(2);
	str_2[0] = str[0];
	str_2[5] = "segundo";
	std::cout << "soy str_2, soy copia: " << str_2[0] << std::endl;
	std::cout << "soy str_2[1], soy copia: " << str_2[1] << std::endl;
	const Array<std::string> str_cpy(str_2);
	std::cout << "soy str_cpy, de constructor de copia const: " << str_cpy[0] << std::endl;
	std::cout << "soy str_cpy[1], de constructor de copia const: " << str_cpy[1] << std::endl;
	str[0] = "funciono";
	std::cout << "soy str_cpy: " << str_cpy[0] << std::endl;
	std::cout << "soy str cambiado: " << str[0] << std::endl;
	return (0);
}

