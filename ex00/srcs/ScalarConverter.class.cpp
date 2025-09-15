/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:37:57 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 19:03:36 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

// ----------------------------------------
// constructors / destructors -------------

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& old_obj)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	(void)old_obj;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& old_obj)
{
	std::cout << "ScalarConverter assignement operator called" << std::endl;

	(void)old_obj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

// constructors / destructors -------------
// ----------------------------------------


// ----------------------------------------
// methods --------------------------------

static void	convertError()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void	convertInt(const std::string& input)
{
	int	inputInt = static_cast<int>(std::strtol(input.c_str(), NULL, 0));

	char	inputChar = static_cast<char>(inputInt);

	if (std::isprint(inputChar))
	{
		std::cout << "char: " << inputChar << std::endl;
	}
	else
	{
		std::cout << "char: non displayable" << std::endl;
	}
	std::cout << "int: " << inputInt << std::endl;
	std::cout << "float: " << static_cast<float>(inputInt) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(inputInt) << ".0" << std::endl;
}

static void	convertDouble(const std::string& input)
{
	double	inputDouble = std::strtod(input.c_str(), NULL);

	char	inputChar = static_cast<char>(inputDouble);

	if (std::isprint(inputChar))
	{
		std::cout << "char: " << inputChar << std::endl;
	}
	else
	{
		std::cout << "char: non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(inputDouble) << std::endl;
	std::cout << "float: " << static_cast<float>(inputDouble) << "f" << std::endl;
	std::cout << "double: " << inputDouble << std::endl;
}


static void	convertFloat(const std::string& input)
{
	float	inputFloat = std::strtof(input.c_str(), NULL);

	char	inputChar = static_cast<char>(inputFloat);

	if (std::isprint(inputChar))
	{
		std::cout << "char: " << inputChar << std::endl;
	}
	else
	{
		std::cout << "char: non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(inputFloat) << std::endl;
	std::cout << "float: " << inputFloat << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(inputFloat) << std::endl;
}

static void	convertElse(const std::string& input)
{
	int	i = 0;

	while (input[i] == ' ')
		i++;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (!std::isdigit(input[i]))
	{
		convertError();
		return;
	}

	int		inputSize = input.size();
	bool	dot = false;

	while (i < inputSize)
	{
		if (input[i] == '.')
		{
			if (dot == false)
				dot = true;
			else
			{
				convertError();
				return;
			}
		}
		else if (input[i] == 'f' && i == (inputSize - 1))
		{
			convertFloat(input);
			return;
		}
		else if (!std::isdigit(input[i]))
		{
			convertError();
			return;
		}
		i++;
	}
	if (dot == true)
		convertDouble(input);
	else
		convertInt(input);
}

static void	convertChar(const std::string& input)
{
	unsigned char	inputChar = static_cast<unsigned char>(input[0]);

	if (std::isprint(inputChar))
	{
		std::cout << "char: " << inputChar << std::endl;
	}
	else
	{
		std::cout << "char: non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(inputChar) << std::endl;
	std::cout << "float: " << static_cast<float>(inputChar) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(inputChar) << ".0" << std::endl;
}

static void	convertSpeFloat(const std::string& input)
{
	float	inputFloat = std::strtof(input.c_str(), NULL);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << inputFloat << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(inputFloat) << std::endl;
}

static void	convertSpeDouble(const std::string& input)
{
	double	inputDouble = std::strtod(input.c_str(), NULL);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(inputDouble) << "f" << std::endl;
	std::cout << "double: " << inputDouble << std::endl;
}

static int	convertSpe(const std::string& input)
{
	std::string	specialList[] = 
	{
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan"
	};

	const std::size_t	listSize = sizeof(specialList) / sizeof(specialList[0]);

	for (std::size_t i = 0; i < listSize; i++)
	{
		if (input == specialList[i])
		{
			if (i < listSize / 2)
			{
				// special float
				convertSpeFloat(input);
				return (1);
			}
			else
			{
				// special double
				convertSpeDouble(input);
				return (1);
			}
		}
	}
	return (0);
}

void	ScalarConverter::convert(const std::string& input)
{
	// spe float & double
	if (convertSpe(input))
		return;

	if (input.size() == 1 && !isdigit(input[0]))
	{
		// char
		convertChar(input);
		return;
	}

	// int, float, double, errors
	convertElse(input);
	return;
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




