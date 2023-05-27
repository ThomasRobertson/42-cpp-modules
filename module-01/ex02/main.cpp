/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:33:04 by troberts          #+#    #+#             */
/*   Updated: 2023/05/26 18:43:09 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address :" << std::endl
		<< "String variable : " << &str << std::endl
		<< "stringPTR : " << stringPTR << std::endl
		<< "stringREF : " << &stringREF << std::endl << std::endl;
	
	std::cout << "Value :" << std::endl
		<< "String variable : " << str << std::endl
		<< "stringPTR : " << *stringPTR << std::endl
		<< "stringREF : " << stringREF << std::endl;
}
