/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.class.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:26:45 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 22:27:14 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.class.hpp"

// ----------------------------------------
// constructors / destructors -------------

C::C()
{
	std::cout << "C default constructor called" << std::endl;
}

C::C(const C& old_obj)
{
	std::cout << "C copy constructor called" << std::endl;
	(void)old_obj;
}

C&	C::operator=(const C& old_obj)
{
	std::cout << "C assignement operator called" << std::endl;

	(void)old_obj;
	return (*this);
}

C::~C()
{
	std::cout << "C destructor called" << std::endl;
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
