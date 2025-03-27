/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:29:48 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/17 16:29:48 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av){
	int x = 1;
	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (x < ac){
		for (int i = 0; av[x][i] != '\0'; i++){
			std::cout << (char)std::toupper(av[x][i]);
		}
		x++;
	}
	std::cout << std::endl;
	return 0;
}