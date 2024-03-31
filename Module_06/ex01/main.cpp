/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:05:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/31 17:37:02 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *ptr = new Data(1);
	uintptr_t raw;

	std::cout << ptr << std::endl;
	raw = Serializer::serialize(ptr);
	Data *ptr_des = Serializer::deserialize(raw);
	std::cout << ptr_des << std::endl;
	delete ptr;
	return (0);
}
