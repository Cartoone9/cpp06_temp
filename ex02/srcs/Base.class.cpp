/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:03:40 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/16 00:19:14 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"
#include "colors.hpp"

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
	Base*	check = NULL;

	check = dynamic_cast<A*>(p);
	if (check != NULL)
	{
		std::cout << "Ptr identified as " << TEAL "A" RESET << std::endl;
		return;
	}
	check = dynamic_cast<B*>(p);
	if (check != NULL)
	{
		std::cout << "Ptr identified as " << YELLOW "B" RESET << std::endl;
		return;
	}
	check = dynamic_cast<C*>(p);
	if (check != NULL)
	{
		std::cout << "Ptr identified as " << RED "C" RESET << std::endl;
		return;
	}
}

void	Base::identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Ref identified as " << TEAL "A" RESET << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "Ref identified as " << YELLOW "B" RESET << std::endl;
			return;
		}
		catch (const std::exception& ex)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "Ref identified as " << RED "C" RESET << std::endl;
				return;
			}
			catch (const std::exception& exc)
			{
				std::cout << "Ref is invalid" << std::endl;
			}
		}
	}
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
