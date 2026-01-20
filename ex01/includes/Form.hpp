/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:01:11 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 13:57:13 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

#define GRADE_TOO_HIGHT "The grade is too hight"
#define GRADE_TOO_LOW "The grade is too low"

class	Bureaucrat;

class	Form
{
	private:
		std::string const	name_;
		bool				isSigned_;
		int const			signRequiredGrade_;
		int const			execRequiredGrade_;
	public:
		Form();
		Form(Form const& form);
		Form(std::string const& name, int const& signRequiredGrade, \
			int const& execRequiredGrade);
		~Form(){};

		Form const&	operator=(Form const& form);

		std::string const&	getName() const;
		bool const&			getIsSigned() const;
		int const&			getSignRequiredGrade() const;
		int const&			getExecRequiredGrade() const;

		void				beSigned(Bureaucrat const& bureaucrat);

		class	GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, Form const& form);

#endif