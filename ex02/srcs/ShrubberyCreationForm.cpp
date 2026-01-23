/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:52:26 by njooris           #+#    #+#             */
/*   Updated: 2026/01/23 15:59:30 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("default", 145, 137, "default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("default", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& form)
: AForm(form)
{}

ShrubberyCreationForm const&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& form)
{
	if (this == &form)
	{
		return (*this);
	}
	setTarget(form.getTarget());
	setIsSigned(form.getIsSigned());
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getExecRequiredGrade())
	{
		throw GradeTooLowException();
	}
	if (getIsSigned() == false)
	{
		throw NotSignedException();
	}
	
	std::ofstream	file_shrubbery((getTarget() + "_shrubbery").c_str());
	if (file_shrubbery.is_open())
	{
		file_shrubbery << TREE;
		file_shrubbery.close();
	}
}