/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:32:32 by njooris           #+#    #+#             */
/*   Updated: 2026/01/26 15:45:50 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm()
:	name_("default"), isSigned_(false), signRequiredGrade_(1), execRequiredGrade_(1), target_("default")
{}

AForm::AForm(AForm const& form)
:	name_(form.name_), isSigned_(form.isSigned_),
	signRequiredGrade_(form.signRequiredGrade_),
	execRequiredGrade_(form.execRequiredGrade_),
	target_(form.target_) 
{}

AForm::AForm(std::string const& name, int signRequiredGrade, 
			int execRequiredGrade, std::string const& target)
:	name_(name), isSigned_(false),
	signRequiredGrade_(signRequiredGrade),
	execRequiredGrade_(execRequiredGrade),
	target_(target)
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

AForm const&	AForm::operator=(AForm const& form)
{
	if (this == &form)
	{
		return (*this);
	}
	isSigned_ = form.isSigned_;
	return (*this);
}

std::string const&	AForm::getName() const
{
	return (name_);
}

bool const&	AForm::getIsSigned() const
{
	return (isSigned_);
}

void	AForm::setIsSigned(bool const& isSigned)
{
	isSigned_ = isSigned;
}

int const&	AForm::getSignRequiredGrade() const
{
	return (signRequiredGrade_);
}

int const&	AForm::getExecRequiredGrade() const
{
	return (execRequiredGrade_);
}

std::string const&	AForm::getTarget() const
{
	return (target_);
}

void	AForm::setTarget(std::string const& target)
{
	target_ = target;
}

void	AForm::beSigned(Bureaucrat const& bureaucrat)
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

const char* AForm::GradeTooHighException::what() const throw()
{
	return (GRADE_TOO_HIGH);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (GRADE_TOO_LOW);
}

const char* AForm::NotSignedException::what() const throw()
{
	return (NOT_SIGNED);
}

std::ostream&	operator<<(std::ostream& os, AForm const& form)
{
	os << "Form :" << std::endl;
	os << "Name : " << form.getName() << std::endl;
	os << "Is signed : " << (form.getIsSigned() ? "yes" : "no") << std::endl;
	os << "Grade to sign : " << form.getSignRequiredGrade() << std::endl;
	os << "Grade to exec : " << form.getExecRequiredGrade() << std::endl;
	return (os);
}