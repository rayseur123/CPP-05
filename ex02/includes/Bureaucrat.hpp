/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:00:11 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 14:17:36 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define GRADE_TOO_HIGHT "The grade is too hight"
#define GRADE_TOO_LOW "The grade is too low"

class	AForm;

class	Bureaucrat
{
	private:
		int					grade_;
		std::string const	name_;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const& bureaucrat);
		Bureaucrat(int const& grade, std::string const& name);

		~Bureaucrat(){};

		Bureaucrat&	operator=(Bureaucrat const& Bureaucrat);
		Bureaucrat	operator++(int);
		Bureaucrat	operator--(int);

		std::string const&	getName() const;
		int const&			getGrade() const;
		
		void				signForm(AForm& form) const;
		
		class	GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& Bureaucrat);

#endif