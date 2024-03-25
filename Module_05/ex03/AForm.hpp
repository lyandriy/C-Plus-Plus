/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:58:41 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/25 18:40:48 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				_signed;
		const int			sign;
		const int			_execute;
	public:
		AForm();
		virtual ~AForm();

		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		AForm(std::string _name, int _sign, int _execute);

		std::string	getName() const;
		bool	getSigned() const;
		int		getSign() const;
		int		getExecute() const;
		void	beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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

	friend std::ostream &operator<<(std::ostream& oso, AForm& other);
};

#endif