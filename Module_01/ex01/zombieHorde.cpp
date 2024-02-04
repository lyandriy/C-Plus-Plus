/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:10:16 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/02 18:04:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*_zombie;

	if (N <= 0)
		return (NULL);
	_zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		_zombie[i].setName(name + "_"+ std::to_string(i));
	return (_zombie);
}
