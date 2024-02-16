/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:52 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/16 19:54:04 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap
{
	public:
	/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/
		ScavTrap(void);
		~ScavTrap();

	/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/
		ScavTrap(const ScavTrap &other);
		ScavTrap	&operator=(const ScavTrap &other);

	/*---CONSTRUCTORS---*/
		ScavTrap(std::string name);

	/*---METHODS---*/
		void	attack(const std::string& target);
		void	guardGate();
};

#endif

