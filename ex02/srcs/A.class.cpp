/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.class.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:24:51 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 22:26:18 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.class.hpp"

// ----------------------------------------
// constructors / destructors -------------

A::A()
{
	std::cout << "A default constructor called" << std::endl;
}

A::A(const A& old_obj)
{
	std::cout << "A copy constructor called" << std::endl;

	(void)old_obj;
}

A&	A::operator=(const A& old_obj)
{
	std::cout << "A assignement operator called" << std::endl;
	
	(void)old_obj;
	return (*this);
}

A::~A()
{
	std::cout << "A destructor called" << std::endl;
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
