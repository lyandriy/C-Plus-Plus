/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:10:15 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/06 17:12:30 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;
	int i = 1;
	while (argv[i])
	{
		ScalarConverter::convert(argv[i]);
		i++;
	}
	return (0);
}