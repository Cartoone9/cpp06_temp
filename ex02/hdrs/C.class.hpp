/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.class.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:26:25 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 22:28:49 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_CLASS_HPP
#define C_CLASS_HPP

#include "Base.class.hpp"

class C : public Base
{
	public:
		// constructors - destructors
		C();
		C(const C& old_obj);
		C& operator=(const C& old_obj);
		~C();

		// methods

		// getters - setters

	private:
		
};

#endif // C_CLASS_HPP
