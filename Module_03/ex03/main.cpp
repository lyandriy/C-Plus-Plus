/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:25 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/16 20:27:35 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	monster("risky");

	monster.attack("robot");
	monster.attack("robot");
	monster.takeDamage(2);
	monster.beRepaired(1);
	monster.whoAmI();
	
	return (0);
}
