/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 17:48:44 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hP;
		unsigned int	_eP;
		unsigned int	_aD;
	public:
	/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/
		ClapTrap();
		~ClapTrap();

	/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/
		ClapTrap(const ClapTrap &other);
		ClapTrap	&operator=(const ClapTrap &other);

	/*---CONSTRUCTORS---*/
		ClapTrap(std::string name);

	/*---METHODS---*/
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif