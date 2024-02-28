/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:52:11 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/25 18:03:27 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();

		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		Ice(std::string const & type);

		Ice*	clone() const;
		void	use(ICharacter& target);
};

#endif