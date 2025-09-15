/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:58:49 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 19:02:18 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"
#include "colors.hpp"

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << RED "Error: " RESET;
		std::cerr << "./scalar arg_to_convert" << std::endl;
		return (1);
	}

	ScalarConverter::convert(static_cast<std::string>(av[1]));

	return (0);
}
