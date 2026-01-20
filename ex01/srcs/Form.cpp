/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:32:32 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 14:14:20 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form()
:	name_("default"), isSigned_(false), signRequiredGrade_(1), execRequiredGrade_(1)
{}

Form::Form(Form const& form)
:	name_(form.name_), isSigned_(form.isSigned_), \
	signRequiredGrade_(form.signRequiredGrade_), \
	execRequiredGrade_(form.execRequiredGrade_)
{}

Form::Form(std::string const& name, int const& signRequiredGrade, \
			int const& execRequiredGrade)
:	name_(name), isSigned_(false), \
	signRequiredGrade_(signRequiredGrade), \
	execRequiredGrade_(execRequiredGrade)
{
	if (signRequiredGrade_ < 1 || execRequiredGrade_ < 1)
	{
		throw (GradeTooHighException());
	}
	if (signRequiredGrade_ > 150 || execRequiredGrade_ > 150)
	{
		throw (GradeTooLowException());
	}
}

Form const&	Form::operator=(Form const& form)
{
	if (this == &form)
	{
		return (*this);
	}
	isSigned_ = form.isSigned_;
	return (*this);
}

std::string const&	Form::getName() const
{
	return (name_);
}

bool const&	Form::getIsSigned() const
{
	return (isSigned_);
}

int const&	Form::getSignRequiredGrade() const
{
	return (signRequiredGrade_);
}

int const&	Form::getExecRequiredGrade() const
{
	return (execRequiredGrade_);
}

void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > signRequiredGrade_)
	{
		throw GradeTooLowException();
	}
	if (isSigned_ == false)
	{
		isSigned_ = true;
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (GRADE_TOO_HIGHT);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (GRADE_TOO_LOW);
}

std::ostream&	operator<<(std::ostream& os, Form const& form)
{
	os << "Form :" << std::endl;
	os << "Name : " << form.getName() << std::endl;
	os << "Is signed : " << (form.getIsSigned() ? "yes" : "no") << std::endl;
	os << "Grade to sign : " << form.getSignRequiredGrade() << std::endl;
	os << "Grade to exec : " << form.getExecRequiredGrade() << std::endl;
	return (os);
}