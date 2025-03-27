/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:15:48 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/18 10:15:48 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

class Phonebook{
    private:
        Contact _contacts[8];

    public:
        Phonebook();
        ~Phonebook();
        void    add(int current_num);
        void    search();
        void    show_phonebook();
        void    display_contact();
        void    print(std::string str) const;

};

#endif