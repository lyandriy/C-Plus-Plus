/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:48 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 18:00:59 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap robot("Trap");

	robot.attack("Clap");
	robot.attack("Clap");
	robot.attack("Clap");
	robot.takeDamage(200);
	robot.beRepaired(40);
	robot.guardGate();
	
	return (0);
}
