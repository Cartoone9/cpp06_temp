/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:25:42 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/15 19:13:26 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
#define SCALARCONVERTER_CLASS_HPP

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
	public:
		// constructors - destructors
		~ScalarConverter();

		// methods
		static void	convert(const std::string& input);

		// getters - setters

	private:
		// constructors - destructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter& old_obj);
		ScalarConverter& operator=(const ScalarConverter& old_obj);

};

#endif // SCALARCONVERTER_CLASS_HPP
