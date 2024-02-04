/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:10:07 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/26 18:38:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main()
{
	Zombie	*zombie;
	
	zombie = zombieHorde(5, "Foo");
	for(int i = 0; i < 5; i++)
		zombie[i].announce();
	delete [] zombie;
}

