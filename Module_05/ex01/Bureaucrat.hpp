/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:22:38 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/27 17:40:26 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

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

		void	iGrade();
		void	dGrade();
		void	signForm(Form &form);

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

};

std::ostream &operator<<(std::ostream& oso, Bureaucrat& other);

#endif