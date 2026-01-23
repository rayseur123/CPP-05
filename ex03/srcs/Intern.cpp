/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:24:07 by njooris           #+#    #+#             */
/*   Updated: 2026/01/22 12:17:27 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern&	Intern::operator=(Intern const& intern)
{
	(void)intern;
	return (*this);
}

enum
{
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL,
	none
};

AForm*	Intern::makeForm(std::string const& name, std::string const& target) const
{
	int 		i = 0;
	AForm*		form = NULL;
	std::string	tabStr[3] = {"shrubbery request", "robotomy request",\
							 "presidential request"};
	
	while (tabStr[i] != name && i < 3)
		i++;
	switch (i)
	{
		case none:
			std::cout << "Intern can't do this form !" << std::endl;
			break;
		case SHRUBBERY:
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			break ;
		case ROBOTOMY:
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			break ;
		case PRESIDENTIAL:
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			break ;
		}
	return (form);
}