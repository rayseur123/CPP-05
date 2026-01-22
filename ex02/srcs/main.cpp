/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:59:39 by njooris           #+#    #+#             */
/*   Updated: 2026/01/22 10:18:06 by njooris          ###   ########.fr       */
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

void	test_1()
{
	std::cout << "Test 1 :" << std::endl;
	try
	{
		Bureaucrat bureaucrat(0, "toto");
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucrat error : " << e.what() << std::endl;
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_2()
{
	std::cout << "Test 2 :" << std::endl;
	try
	{
		Bureaucrat bureaucrat(151, "toto");
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucrat error : " << e.what() << std::endl;
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_3()
{
	std::cout << "Test 3 :" << std::endl;
	try
	{
		Bureaucrat bureaucrat(75, "toto");
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucrat error : " << e.what() << std::endl;
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_4()
{
	std::cout << "Test 4 :" << std::endl;
	try
	{
		Bureaucrat bureaucrat(150, "toto");
		bureaucrat--;
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucrat error : " << e.what() << std::endl;
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_5()
{
	std::cout << "Test 5 :" << std::endl;
	try
	{
		Bureaucrat bureaucrat(1, "toto");
		bureaucrat++;
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucrat error : " << e.what() << std::endl;
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_6()
{
	std::cout << "Test 6 :" << std::endl;
	Bureaucrat bureaucrat(1, "toto");

	std::cout << bureaucrat << std::endl;
}

void	test_7()
{
	std::cout << "Test 7 :" << std::endl;
	try
	{
		AForm*		form = new ShrubberyCreationForm();
		Bureaucrat	bureaucrat(1, "toto");
		
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		delete form;
	}
	catch (std::exception & e)
	{
		std::cout << "ShrubberyCreationForm error : " << e.what() << std::endl;
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_8()
{
	std::cout << "Test 8 :" << std::endl;
	try
	{
		AForm*		form = new RobotomyRequestForm();
		Bureaucrat	bureaucrat(1, "toto");
		
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		delete form;
	}
	catch (std::exception & e)
	{
		std::cout << "RobotomyRequestForm error : " << e.what() << std::endl;
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_9()
{
	std::cout << "Test 9 :" << std::endl;
	try
	{
		AForm*		form = new PresidentialPardonForm();
		Bureaucrat	bureaucrat(1, "toto");

		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		delete form;
	}
	catch (std::exception & e)
	{
		std::cout << "PresidentialPardonForm error : " << e.what() << std::endl;
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_10()
{
	std::cout << "Test 10 :" << std::endl;
	try
	{
		Bureaucrat	bureaucrat(145, "toto");
		AForm*	form = new ShrubberyCreationForm();
		
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_11()
{
	std::cout << "Test 11 :" << std::endl;
	try
	{
		Bureaucrat	bureaucrat(72, "toto");
		AForm*	form = new RobotomyRequestForm();
		
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << "No error" << std::endl;
}

void	test_12()
{
	std::cout << "Test 12 :" << std::endl;
	try
	{
		Bureaucrat	bureaucrat(25, "toto");
		AForm*	form = new PresidentialPardonForm();
		
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << "No error" << std::endl;
}

int	main()
{
	srand (time(NULL));
	test_1();
	std::cout << std::endl;
	test_2();
	std::cout << std::endl;
	test_3();
	std::cout << std::endl;
	test_4();
	std::cout << std::endl;
	test_5();
	std::cout << std::endl;
	test_6();
	std::cout << std::endl;
	test_7();
	std::cout << std::endl;
	test_8();
	std::cout << std::endl;
	test_9();
	std::cout << std::endl;
	test_10();
	std::cout << std::endl;
	test_11();
	std::cout << std::endl;
	test_12();
	return (0);
}