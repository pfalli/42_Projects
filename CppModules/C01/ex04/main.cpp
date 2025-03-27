/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:34:19 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/24 15:34:19 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main ( int ac, char **av )
{
    if (ac != 4) {
        std::cout << "Usage: ./main [filename] [s1] [s2]." << std::endl;
        return 1;
    }
    else {
        Sed   sed2(av[1]);
        sed2.replace(av[2], av[3]);
    }
    return 0;
}