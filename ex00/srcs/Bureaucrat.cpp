/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:13:36 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 11:51:54 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: grade_ (1), name_("default"){}

Bureaucrat::Bureaucrat(Bureaucrat const& bureaucrat)
: grade_(bureaucrat.grade_), name_(bureaucrat.name_){}

Bureaucrat::Bureaucrat(int const& grade, std::string const& name)
: grade_(grade), name_(name)
{
	if (grade_ < 1)
	{
		throw (GradeTooHighException());
	}
	if (grade_ > 150)
	{
		throw (GradeTooLowException());
	}
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& bureaucrat)
{
	if (this == &bureaucrat)
	{
		return (*this);
	}
	grade_ = bureaucrat.grade_;
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat	ret(*this);
	
	grade_--;
	if (grade_ < 1)
	{
		throw (GradeTooHighException());
	}
	return (ret);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat	ret(*this);
	
	grade_++;
	if (grade_ > 150)
	{
		throw (GradeTooLowException());
	}
	return (ret);
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& Bureaucrat)
{
	os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << ".";
	return (os);	
}

std::string const&	Bureaucrat::getName() const
{
	return (name_);	
}

int const&	Bureaucrat::getGrade() const
{
	return (grade_);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (GRADE_TOO_HIGHT);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (GRADE_TOO_HIGHT);
}