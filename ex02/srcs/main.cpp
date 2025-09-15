/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:00:25 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/16 00:08:22 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"
#include "colors.hpp"

int	main()
{
	Base	generator;

	Base*	random_ptr_1;
	Base*	random_ptr_2;
	Base*	random_ptr_3;

	random_ptr_1 = generator.generate();
	random_ptr_2 = generator.generate();
	random_ptr_3 = generator.generate();

	std::cout << std::endl;
	std::cout << UNDERLINE TEAL "Ptr identify:" RESET << std::endl;

	generator.identify(random_ptr_1);
	generator.identify(random_ptr_2);
	generator.identify(random_ptr_3);

	std::cout << std::endl;

	Base&	random_ref_1 = *random_ptr_1;
	Base&	random_ref_2 = *random_ptr_2;
	Base&	random_ref_3 = *random_ptr_3;

	std::cout << UNDERLINE MAGENTA "Ref identify:" RESET << std::endl;

	generator.identify(random_ref_1);
	generator.identify(random_ref_2);
	generator.identify(random_ref_3);
	
	std::cout << std::endl;

	delete (random_ptr_1);
	delete (random_ptr_2);
	delete (random_ptr_3);

	return (0);
}
