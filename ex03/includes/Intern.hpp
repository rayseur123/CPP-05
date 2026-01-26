/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:53:29 by njooris           #+#    #+#             */
/*   Updated: 2026/01/26 15:54:05 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern& intern);
		~Intern();

		Intern&	operator=(Intern const& intern);
		AForm*	makeForm(std::string const& name, std::string const& target) const;
};

#endif