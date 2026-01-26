/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:00:11 by njooris           #+#    #+#             */
/*   Updated: 2026/01/26 15:51:18 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define GRADE_TOO_HIGH "The grade is too high"
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
		Bureaucrat(int grade, std::string const& name);

		~Bureaucrat();

		Bureaucrat&	operator=(Bureaucrat const& Bureaucrat);
		Bureaucrat	operator++(int);
		Bureaucrat	operator--(int);

		std::string const&	getName() const;
		int const&			getGrade() const;
		
		void				signForm(AForm& form) const;
		void				executeForm(AForm const& form) const;
		
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