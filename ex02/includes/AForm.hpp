/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:01:11 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 16:05:39 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

#define GRADE_TOO_HIGHT "The grade is too hight"
#define GRADE_TOO_LOW "The grade is too low"

class	Bureaucrat;

class	AForm
{
	protected:
		std::string const	name_;
		bool				isSigned_;
		int const			signRequiredGrade_;
		int const			execRequiredGrade_;
		std::string			target_;
	public:
		AForm();
		AForm(AForm const& form);
		AForm(std::string const& name, int const& signRequiredGrade, \
			int const& execRequiredGrade, std::string const& target);
		virtual	~AForm(){};

		AForm const&	operator=(AForm const& form);

		std::string const&	getName() const;
		bool const&			getIsSigned() const;
		int const&			getSignRequiredGrade() const;
		int const&			getExecRequiredGrade() const;

		void				beSigned(Bureaucrat const& bureaucrat);
		virtual void		execute(Bureaucrat const& executor) const = 0;
		
		class	GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, AForm const& form);

#endif