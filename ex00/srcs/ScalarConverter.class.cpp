/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:37:57 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 20:39:41 by jramiro          ###   ########.fr       */
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
	std::cout << TEAL "char: " RESET << "impossible" << std::endl;
	std::cout << BLUE "int: " RESET << "impossible" << std::endl;
	std::cout << PURPLE "float: " RESET << "impossible" << std::endl;
	std::cout << MAGENTA "double: " RESET << "impossible" << std::endl;
}

static void	convertInt(const std::string& input)
{
	long long	inputInt = std::strtol(input.c_str(), NULL, 0);

	if (errno == ERANGE)
	{
		errno = 0;
		convertError();
		return;
	}

	unsigned char	inputChar = static_cast<unsigned char>(inputInt);

	// char
	if (inputInt < 0 || inputInt > 127)
		std::cout << TEAL "char: " RESET << "impossible" << std::endl;
	else if (!std::isprint(inputChar))
		std::cout << TEAL "char: " RESET << "non displayable" << std::endl;
	else
		std::cout << TEAL "char: " RESET << inputChar << std::endl;

	// int
	if (inputInt > std::numeric_limits<int>::max()
		|| inputInt < std::numeric_limits<int>::min())
		std::cout << BLUE "int: " RESET << "impossible" << std::endl;
	else
		std::cout << BLUE "int: " RESET << inputInt << std::endl;

	// float
	if (static_cast<float>(inputInt) > std::numeric_limits<float>::max()
		|| static_cast<float>(inputInt) < -std::numeric_limits<float>::max())
		std::cout << PURPLE "float: " RESET << "impossible" << std::endl;
	else
		std::cout << PURPLE "float: " RESET << static_cast<float>(inputInt) << ".0f" << std::endl;

	// double
	if (static_cast<double>(inputInt) > std::numeric_limits<double>::max()
		|| static_cast<double>(inputInt) < -std::numeric_limits<double>::max())
		std::cout << MAGENTA "double: " RESET << "impossible" << std::endl;
	else
		std::cout << MAGENTA "double: " RESET << static_cast<double>(inputInt) << ".0" << std::endl;
}

static void	convertDouble(const std::string& input)
{
	double	inputDouble = std::strtod(input.c_str(), NULL);

	if (errno == ERANGE)
	{
		errno = 0;
		convertError();
		return;
	}

	unsigned char	inputChar = static_cast<unsigned char>(inputDouble);

	// char
	if (inputDouble < 0.0 || inputDouble > 127.0)
		std::cout << TEAL "char: " RESET << "impossible" << std::endl;
	else if (!std::isprint(inputChar))
		std::cout << TEAL "char: " RESET << "non displayable" << std::endl;
	else
		std::cout << TEAL "char: " RESET << inputChar << std::endl;

	// int
	if (inputDouble > static_cast<double>(std::numeric_limits<int>::max())
		|| inputDouble < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << BLUE "int: " RESET << "impossible" << std::endl;
	else
		std::cout << BLUE "int: " RESET << static_cast<int>(inputDouble) << std::endl;

	bool full = false;
	if (inputDouble == static_cast<int>(inputDouble))
		full = true;

	// float
	std::cout << PURPLE "float: " RESET << static_cast<float>(inputDouble);

	if (full == true)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	// double
	std::cout << MAGENTA "double: " RESET << inputDouble;

	if (full == true)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}


static void	convertFloat(const std::string& input)
{
	float	inputFloat = std::strtof(input.c_str(), NULL);

	if (errno == ERANGE)
	{
		errno = 0;
		convertError();
		return;
	}

	unsigned char	inputChar = static_cast<unsigned char>(inputFloat);

	// char
	if (inputFloat < 0.0f || inputFloat > 127.0f)
		std::cout << TEAL "char: " RESET << "impossible" << std::endl;
	else if (!std::isprint(inputChar))
		std::cout << TEAL "char: " RESET << "non displayable" << std::endl;
	else
		std::cout << TEAL "char: " RESET << inputChar << std::endl;

	// int
	if (inputFloat > static_cast<float>(std::numeric_limits<int>::max())
		|| inputFloat < static_cast<float>(std::numeric_limits<int>::min()))
		std::cout << BLUE "int: " RESET << "impossible" << std::endl;
	else
		std::cout << BLUE "int: " RESET << static_cast<int>(inputFloat) << std::endl;

	bool full = false;
	if (inputFloat == static_cast<int>(inputFloat))
		full = true;

	// float
	std::cout << PURPLE "float: " RESET << static_cast<float>(inputFloat);

	if (full == true)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	// double
	std::cout << MAGENTA "double: " RESET << inputFloat;

	if (full == true)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

static void	convertElse(const std::string& input)
{
	int	i = 0;

	// while (input[i] == ' ')
	// 	i++;

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
			if (dot == true || i == (inputSize - 1)
				|| (i == (inputSize - 2) && input[i + 1] == 'f'))
			{
				convertError();
				return;
			}
			dot = true;
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

	if (!std::isprint(inputChar))
		std::cout << TEAL "char: " RESET << "non displayable" << std::endl;
	else
		std::cout << TEAL "char: " RESET << inputChar << std::endl;

	std::cout << BLUE "int: " RESET << static_cast<int>(inputChar) << std::endl;
	std::cout << PURPLE "float: " RESET << static_cast<float>(inputChar) << ".0f" << std::endl;
	std::cout << MAGENTA "double: " RESET << static_cast<double>(inputChar) << ".0" << std::endl;
}

static void	convertSpeFloat(const std::string& input)
{
	float	inputFloat = std::strtof(input.c_str(), NULL);

	std::cout << TEAL "char: " RESET << "impossible" << std::endl;
	std::cout << BLUE "int: " RESET << "impossible" << std::endl;
	std::cout << PURPLE "float: " RESET << inputFloat << "f" << std::endl;
	std::cout << MAGENTA "double: " RESET << static_cast<double>(inputFloat) << std::endl;
}

static void	convertSpeDouble(const std::string& input)
{
	double	inputDouble = std::strtod(input.c_str(), NULL);

	std::cout << TEAL "char: " RESET << "impossible" << std::endl;
	std::cout << BLUE "int: " RESET << "impossible" << std::endl;
	std::cout << PURPLE "float: " RESET << static_cast<float>(inputDouble) << "f" << std::endl;
	std::cout << MAGENTA "double: " RESET << inputDouble << std::endl;
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
