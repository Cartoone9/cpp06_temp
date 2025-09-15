/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:58:49 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 20:45:38 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"
#include "colors.hpp"

int	main(int ac, char** av)
{
	if (ac == 1)
	{
		std::cerr << RED "Error: " RESET;
		std::cerr << "./scalar arg1_to_convert [arg2_to_convert ...]" << std::endl;
		
		return (1);
	}

	std::cout << std::endl;

	for (int i = 1; i < ac; i++)
	{
		std::cout << REVERSED " arg [" << i << "]: " << av[i] << " " RESET << std::endl;

		ScalarConverter::convert(static_cast<std::string>(av[i]));
		
		if (i + 1 != ac)
			std::cout << std::endl;
	}

	return (0);
}
