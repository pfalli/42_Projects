/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:29:33 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/24 16:29:33 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Sed
{
    private:
        std::string _inFile;
        std::string _outFile;

    public:
        Sed(std::string filename);
        ~Sed();
        void    replace( std::string s1, std::string s2);
};

#endif // SED_HPP
