/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:03:40 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 22:40:35 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"

// ----------------------------------------
// constructors / destructors -------------

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

// constructors / destructors -------------
// ----------------------------------------


// ----------------------------------------
// methods --------------------------------

static int	randomGen()
{
	static bool seed = (std::srand(std::time(NULL)), true);

	(void)seed;
	int i = std::rand();
	return (i % 3);
}

Base*	Base::generate(void)
{
	int	which = randomGen();

	if (which == 0)
		return (new A());
	else if (which == 1)
		return (new B());
	else
		return (new C());
}	

void	Base::identify(Base* p)
{
	// TODO 
	// Idk if that works
	Base*	check;

	check = dynamic_cast<A*>(p);
	if (check != NULL)
	{
		std::cout << "Ptr identified as A" << std::endl;
		return;
	}
	check = dynamic_cast<B*>(p);
	if (check != NULL)
	{
		std::cout << "Ptr identified as B" << std::endl;
		return;
	}
	check = dynamic_cast<C*>(p);
	if (check != NULL)
	{
		std::cout << "Ptr identified as C" << std::endl;
		return;
	}
}

void	Base::identify(Base& p)
{
	// TODO 
	// that's bad
	if (dynamic_cast<A>(p) != NULL)
		std::cout << "Ref identified as A" << std::endl;
	else if (dynamic_cast<B>(p) != NULL)
		std::cout << "Ref identified as B" << std::endl;
	else if (dynamic_cast<C>(p) != NULL)
		std::cout << "Ref identified as C" << std::endl;
}

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
