/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:01:45 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 23:56:03 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
#define BASE_CLASS_HPP

#include <exception>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
	public:
		// constructors - destructors
		virtual ~Base();

		// methods
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);

		// getters - setters

	private:
		
};

#endif // BASE_CLASS_HPP
