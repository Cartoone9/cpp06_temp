/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:49:36 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 21:40:39 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"
#include "colors.hpp"

int	main()
{
	Data	data;
	Data*	data_ptr;

	data.i = 42;
	data.d = 420.042;
	data_ptr = &data;

	std::cout << REVERSED TEAL "data_ptr:" RESET " " << data_ptr << std::endl;
	std::cout << std::endl;
	std::cout << UNDERLINE "data_ptr values:" RESET << std::endl;
	std::cout << "int: " << data_ptr->i << std::endl;
	std::cout << "double: " << data_ptr->d << std::endl;
	std::cout << std::endl;

	uintptr_t	serial_ptr;
	serial_ptr = Serializer::serialize(data_ptr);

	std::cout << REVERSED PURPLE "serialized ptr:" RESET " " << serial_ptr << std::endl;
	std::cout << std::endl;
	
	Data*	new_data_ptr;
	new_data_ptr = Serializer::deserialize(serial_ptr);

	std::cout << REVERSED MAGENTA "new_data_ptr:" RESET " " << new_data_ptr << std::endl;
	std::cout << std::endl;
	std::cout << UNDERLINE "new_data_ptr values:" RESET << std::endl;
	std::cout << "int: " << new_data_ptr->i << std::endl;
	std::cout << "double: " << new_data_ptr->d << std::endl;

	return (0);
}
