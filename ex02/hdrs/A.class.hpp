/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.class.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:24:27 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 22:28:54 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_CLASS_HPP
#define A_CLASS_HPP

#include "Base.class.hpp"

class A : public Base
{
	public:
		// constructors - destructors
		A();
		A(const A& old_obj);
		A& operator=(const A& old_obj);
		~A();

		// methods

		// getters - setters

	private:
		
};

#endif // A_CLASS_HPP
