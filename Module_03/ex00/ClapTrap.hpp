/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:12:41 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/15 17:02:21 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hP;//puntos de vida //pierde cuando le atacan//recupera cuando se repara
		int			_eP;//puntos de energia//pierde al repararse o atacar
		int			_aD;//puntos de daño de ataque
	public:
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap(const ClapTrap &other);
		ClapTrap	&operator=(const ClapTrap &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif