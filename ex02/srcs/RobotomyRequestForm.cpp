/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:41:36 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 17:20:51 by njooris          ###   ########.fr       */
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

RobotomyRequestForm const&	RobotomyRequestForm::operator=(RobotomyRequestForm const& form)
{
	if (this == &form)
	{
		return (*this);
	}
	target_ = form.target_;
	isSigned_ = form.isSigned_;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > execRequiredGrade_)
	{
		throw GradeTooLowException();
	}
	if (isSigned_ == false)
	{
		throw NotSignedException();
	}
	std::cout << "frrrr drrr zrrrr" << std::endl;
	std::cout << (rand() % 2 ? "Successfully robotomized \n" : "Robotomy failed\n");
}