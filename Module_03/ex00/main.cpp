/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:12:38 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/14 15:46:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Trap("Trap");
	ClapTrap	Clap("Clap");

	Clap.attack("Trap");
	Clap.attack("Trap");
	Trap.attack("Clap");
	Clap.takeDamage(2);

	return (0);
}