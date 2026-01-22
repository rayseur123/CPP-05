/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:59:39 by njooris           #+#    #+#             */
/*   Updated: 2026/01/22 12:15:44 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Bureaucrat.hpp>
#include <exception>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	test_1()
{
	std::cout << "Test 1 :" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat	bureaucrat;
	
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf->execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete(rrf);
}

void	test_2()
{
	std::cout << "Test 2 :" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	try
	{
		rrf = someRandomIntern.makeForm("bad request", "Bender");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	srand (time(NULL));
	test_1();
	std::cout << std::endl;
	test_2();
	return (0);
}