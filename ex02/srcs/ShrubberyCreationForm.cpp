/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:52:26 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 16:20:58 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("default", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& form)
: AForm(form)
{}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() < execRequiredGrade_)
	{
		throw GradeTooLowException();
	}
	
	std::ofstream	file_shrubbery((target_ + "_shrubbery").c_str());
		if (file_shrubbery.is_open())
	{
		file_shrubbery << TREE;
	}
	file_shrubbery.close();
}