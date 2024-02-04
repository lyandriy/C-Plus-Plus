/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:54:24 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/26 16:49:43 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*_zombie;

	_zombie = newZombie("Fii");
	_zombie->announce();
	delete	_zombie;
	randomChump("Fuu");
	return 0;
}
