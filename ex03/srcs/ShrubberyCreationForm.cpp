/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:52:26 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 17:12:06 by njooris          ###   ########.fr       */
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
	target_ = form.target_;
	isSigned_ = form.isSigned_;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > execRequiredGrade_)
	{
		throw GradeTooLowException();
	}
	if (isSigned_ == false)
	{
		throw NotSignedException();
	}
	
	std::ofstream	file_shrubbery((target_ + "_shrubbery").c_str());
		if (file_shrubbery.is_open())
	{
		file_shrubbery << TREE;
	}
	file_shrubbery.close();
}