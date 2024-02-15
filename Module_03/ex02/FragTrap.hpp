/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:02 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/15 19:48:26 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap();

		FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);

		FragTrap(std::string name);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
		void	operato(void);
};

#endif