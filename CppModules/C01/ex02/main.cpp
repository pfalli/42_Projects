/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:12:46 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/23 16:01:33 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPtr = &string;
	std::string &stringRef = string;

	std::cout << "Memory address string: " << &string << std::endl;
	std::cout << "Memory address stringPtr: " << stringPtr << std::endl;
	std::cout << "Memory address stringRef: " << &stringRef << std::endl;

	std::cout << "Value string: " << string << std::endl;
	std::cout << "Value stringPtr: " << *stringPtr << std::endl;
	std::cout << "Value stringRef: " << stringRef << std::endl;
	return 0;
}
