/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:52:06 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/24 12:02:33 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	protected:
		std::string	type;
	public:
		Cure();
		virtual ~Cure();

		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		Cure(std::string const & type);

		std::string const & getType() const;
		Cure*	clone() const ;
		void	use(ICharacter& target);
};

#endif