/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:47:14 by ikotvits          #+#    #+#             */
/*   Updated: 2018/10/01 12:47:16 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (*++argv)
		while (**argv)
		{
			if (**argv > 96 && **argv < 123)
				std::cout << (char)(**argv - ' ');
			else
				std::cout << **argv;
			(*argv)++;
		}
	std::cout << std::endl;
	return (0);
}