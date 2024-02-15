/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/15 19:11:11 by lyandriy         ###   ########.fr       */
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
		ClapTrap();
		~ClapTrap();

		ClapTrap(const ClapTrap &other);
		ClapTrap	&operator=(const ClapTrap &other);

		ClapTrap(std::string name);
		ClapTrap(std::string name, int _hP_, int _eP_, int _aD_);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		/*std::string	getName(void) const;
		int	get_hP(void) const;
		int	get_eP(void) const;
		int	get_aD(void) const;

		void	setName(std::string name);
		void	set_hP(int hP);
		void	set_eP(int eP);
		void	set_aD(int aD);*/

};

#endif