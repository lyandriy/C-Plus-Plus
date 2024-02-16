/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:48 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/16 20:27:29 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap robot("Trap");

	robot.attack("Clap");
	robot.attack("Clap");
	robot.attack("Clap");
	robot.takeDamage(2);
	robot.beRepaired(1);
	robot.guardGate();
	
	return (0);
}
