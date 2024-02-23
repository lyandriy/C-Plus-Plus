/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:18 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 18:18:24 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	DiamName;
	public:
	/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/
		DiamondTrap();
		~DiamondTrap();

	/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap	&operator=(const DiamondTrap &other);

	/*---CONSTRUCTORS---*/
		DiamondTrap(std::string name);

	/*---METHODS---*/
		void	attack(const std::string& target);
		void	whoAmI();
};

#endif