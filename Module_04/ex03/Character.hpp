/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:44 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/25 18:04:33 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARACTER_HPP
#define CARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		int			stock_mat;
		AMateria	*materia[4];
		int			_unequip;
		AMateria	*unequip_materia[100];
	public:
		Character();
		~Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
		Character(std::string const& name);

		std::string const	&getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif