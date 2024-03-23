/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:55:31 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/23 17:29:34 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string	name;
		int					Grade;
	public:
		Bureaucrat();
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat & other);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(int grade, std::string name);

		std::string	getName() const;
		int	getGrade() const;

		void	iGrade(int increment);
		void	dGrade(int decrement);
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);

		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		friend std::ostream &operator<<(std::ostream& oso, Bureaucrat& other);
};

#endif