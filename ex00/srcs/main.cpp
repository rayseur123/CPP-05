/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:59:39 by njooris           #+#    #+#             */
/*   Updated: 2026/01/20 11:54:01 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Bureaucrat.hpp>
#include <exception>

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

int	main()
{
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
	return (0);
}