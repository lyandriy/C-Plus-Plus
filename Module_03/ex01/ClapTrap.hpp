/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/16 19:39:09 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hP;
		int			_eP;
		int			_aD;
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