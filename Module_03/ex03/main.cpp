/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:25 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/24 10:20:57 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	monster("hola");

	monster.attack("robot");
	monster.attack("robot");
	monster.takeDamage(200);
	monster.takeDamage(21);
	monster.beRepaired(300);
	monster.whoAmI();
	
	return (0);
}
