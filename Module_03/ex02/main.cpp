/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:04 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/17 18:47:20 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap robot("Trap");

	robot.attack("Clap");
	robot.attack("Clap");
	robot.attack("Clap");
	robot.takeDamage(2);
	robot.beRepaired(1);
	robot.highFivesGuys();
	
	return (0);
}