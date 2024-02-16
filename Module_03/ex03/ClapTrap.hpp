/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/16 20:01:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hP;//Hit points
		int			_eP;//Energy points
		int			_aD;//Attack damage
	public:
	/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/
		ClapTrap();
		~ClapTrap();

	/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/
		ClapTrap(const ClapTrap &other);
		ClapTrap	&operator=(const ClapTrap &other);

	/*---CONSTRUCTORS---*/
		ClapTrap(std::string name);
		ClapTrap(std::string name, int _hP_, int _eP_, int _aD_);

	/*---METHODS---*/
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif