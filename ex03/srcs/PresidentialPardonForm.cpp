/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:56:49 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 17:12:11 by njooris          ###   ########.fr       */
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

PresidentialPardonForm const&	PresidentialPardonForm::operator=(PresidentialPardonForm const& form)
{
	if (this == &form)
	{
		return (*this);
	}
	target_ = form.target_;
	isSigned_ = form.isSigned_;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > execRequiredGrade_)
	{
		throw GradeTooLowException();
	}
	if (isSigned_ == false)
	{
		throw NotSignedException();
	}

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}