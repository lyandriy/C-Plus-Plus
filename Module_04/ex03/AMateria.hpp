/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:23:57 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/24 12:17:26 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria();
		virtual ~AMateria();

		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		AMateria(std::string const &type);

		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif