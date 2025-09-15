/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:49:55 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 20:52:03 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
#define SERIALIZER_CLASS_HPP

class Serializer
{
	public:
		// constructors - destructors
		~Serializer();

		// methods
		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);

		// getters - setters

	private:
		Serializer();
		Serializer(const Serializer& old_obj);
		Serializer& operator=(const Serializer& old_obj);
		
};

#endif // SERIALIZER_CLASS_HPP
