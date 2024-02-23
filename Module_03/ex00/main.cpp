/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:12:38 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 17:55:40 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Clap("Clap");

	Clap.attack("Trap");
	Clap.attack("Trap");
	Clap.attack("Trap");
	Clap.attack("Trap");
	Clap.attack("Trap");
	Clap.attack("Trap");
	Clap.attack("Trap");
	Clap.attack("Trap");
	//Clap.attack("Trap");
	//Clap.attack("Trap");
	//Clap.attack("Trap");
	Clap.takeDamage(9);
	Clap.takeDamage(2);
	Clap.beRepaired(2);

	return (0);
}