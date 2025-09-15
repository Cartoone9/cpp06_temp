/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:37:57 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/14 20:03:56 by jramiro          ###   ########.fr       */
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

static void	convertSpeFloat(const std::string& input)
{
	float	inputFloat = std::stof(input);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << inputFloat << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(inputFloat) << std::endl;
}

static void	convertSpeDouble(const std::string& input)
{
	double	inputDouble = std::stod(input);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(inputDouble) << "f" << std::endl;
	std::cout << "double: " << inputDouble << std::endl;
}

static void	convertChar(const std::string& input)
{
	char	inputChar = input[0];

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

static void	convertFloat(float inputFloat)
{
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

static void	convertDouble(double inputDouble)
{
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

static void	convertInt(int inputInt)
{
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

static void	convertError()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void	convertElse(const std::string& input)
{
	try
	{
		int	inputInt = std::stoi(input);
		convertInt(inputInt);
	}
	catch (const std::exception& e)
	{
		try
		{
			double	inputDouble = std::stod(input);
			convertDouble(inputDouble);
		}
		catch (const std::exception& ex)
		{
			try
			{
				float	inputFloat = std::stof(input);
				convertFloat(inputFloat);
			}
			catch (const std::exception& exc)
			{
				convertError();
			}
		}
	}
}

void	convert(const std::string& input)
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
				return;
			}
			else
			{
				// special double
				convertSpeDouble(input);
				return;
			}
		}
	}

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
