/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:48:03 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/25 15:29:26 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_SOURCE_HPP
#define MATERIAL_SOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		int			stock_mat;
		AMateria	*materia[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);

		void	learnMateria(AMateria*);
		AMateria*	createMateria(std::string const &type);
};

#endif