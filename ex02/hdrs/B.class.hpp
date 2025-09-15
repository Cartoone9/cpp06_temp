/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.class.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:25:32 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 22:28:58 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_CLASS_HPP
#define B_CLASS_HPP

#include "Base.class.hpp"

class B : public Base
{
	public:
		// constructors - destructors
		B();
		B(const B& old_obj);
		B& operator=(const B& old_obj);
		~B();

		// methods

		// getters - setters

	private:
		
};

#endif // B_CLASS_HPP
