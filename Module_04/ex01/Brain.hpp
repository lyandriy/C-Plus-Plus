/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:38:47 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/02 16:56:27 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		int	count;
		std::string	ideas[100];
	public:
		Brain();
		~Brain();

		void		setIdeas(std::string other);
		std::string	getIdeas(int);
		Brain(const Brain &other);
		Brain	&operator=(const Brain &other);
};

#endif