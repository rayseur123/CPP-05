/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:41:36 by njooris           #+#    #+#             */
/*   Updated: 2026/01/26 15:52:21 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("default", 72, 45, "default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
: AForm("default", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& form)
: AForm(form)
{}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm const&	RobotomyRequestForm::operator=(RobotomyRequestForm const& form)
{
	if (this == &form)
	{
		return (*this);
	}
	setTarget(form.getTarget());
	setIsSigned(form.getIsSigned());
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getExecRequiredGrade())
	{
		throw GradeTooLowException();
	}
	if (getIsSigned() == false)
	{
		throw NotSignedException();
	}
	std::cout << "frrrr drrr zrrrr" << std::endl;
	std::cout << (rand() % 2 ? "Successfully robotomized \n" : "Robotomy failed\n");
}