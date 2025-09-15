/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.class.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:25:55 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 22:26:12 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.class.hpp"

// ----------------------------------------
// constructors / destructors -------------

B::B()
{
	std::cout << "B default constructor called" << std::endl;
}

B::B(const B& old_obj)
{
	std::cout << "B copy constructor called" << std::endl;

	(void)old_obj;
}

B&	B::operator=(const B& old_obj)
{
	std::cout << "B assignement operator called" << std::endl;

	(void)old_obj;
	return (*this);
}

B::~B()
{
	std::cout << "B destructor called" << std::endl;
}

// constructors / destructors -------------
// ----------------------------------------


// ----------------------------------------
// methods --------------------------------

// methods --------------------------------
// ----------------------------------------


// ----------------------------------------
// getters / setters ----------------------

// getters / setters ----------------------
// ----------------------------------------


// ----------------------------------------
// operators overload ---------------------

// operators overload ---------------------
// ----------------------------------------
