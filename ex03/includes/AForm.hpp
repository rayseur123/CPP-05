/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:01:11 by njooris           #+#    #+#             */
/*   Updated: 2026/01/26 15:46:17 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

#define GRADE_TOO_HIGH "The grade is too high"
#define GRADE_TOO_LOW "The grade is too low"
#define NOT_SIGNED "The form are not signed"

class	Bureaucrat;

class	AForm
{
	private:
		std::string const	name_;
		bool				isSigned_;
		int const			signRequiredGrade_;
		int const			execRequiredGrade_;
		std::string			target_;
	public:
		AForm();
		AForm(AForm const& form);
		AForm(std::string const& name, int signRequiredGrade,
			int execRequiredGrade, std::string const& target);
		virtual	~AForm(){};

		AForm const&	operator=(AForm const& form);

		std::string const&	getName() const;
		
		bool const&			getIsSigned() const;
		void				setIsSigned(bool const& isSigned);

		int const&			getSignRequiredGrade() const;
		int const&			getExecRequiredGrade() const;
		
		std::string const&	getTarget() const;
		void				setTarget(std::string const& target);
		
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
		
		class	NotSignedException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, AForm const& form);

#endif