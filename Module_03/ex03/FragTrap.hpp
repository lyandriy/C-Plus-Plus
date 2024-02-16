/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:02 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/16 19:54:09 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : public virtual ClapTrap
{
	public:
	/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/
		FragTrap(void);
		~FragTrap();

	/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/
		FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);

	/*---CONSTRUCTORS---*/
		FragTrap(std::string name);

	/*---METHODS---*/
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif