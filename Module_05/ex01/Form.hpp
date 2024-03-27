/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:53:27 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/27 17:40:17 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				_signed;
		const int			sign;
		const int			execute;
	public:
		Form();
		~Form();

		Form(const Form &other);
		Form &operator=(const Form &other);
		Form(std::string _name, int _sign, int _execute);

		std::string	getName();
		bool	getSigned();
		int		getSign();
		int		getExecute();

		void	beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream& oso, Form& other);

#endif