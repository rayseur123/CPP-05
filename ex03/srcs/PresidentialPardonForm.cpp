/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:56:49 by njooris           #+#    #+#             */
/*   Updated: 2026/01/26 15:55:23 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <cstdlib>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
: AForm("default", 25, 5, "default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
: AForm("default", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& form)
: AForm(form)
{}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm const&	PresidentialPardonForm::operator=(PresidentialPardonForm const& form)
{
	if (this == &form)
	{
		return (*this);
	}
	setTarget(form.getTarget());
	setIsSigned(form.getIsSigned());
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getExecRequiredGrade())
	{
		throw GradeTooLowException();
	}
	if (getIsSigned() == false)
	{
		throw NotSignedException();
	}

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}