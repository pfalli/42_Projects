/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:59:22 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/18 10:59:22 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
 #define CONTACT_HPP

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"

#include <string>
#include <cstdlib>

class Contact{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecrets;
        int _index;
        

    public:
        Contact();
        ~Contact();
        void addInfo(int current_num);
        void printInfo() const;
        std::string is_valid(std::string info, std::string str);
        void    showInfo();
        std::string printLen(std::string str) const;
		std::string is_phonenumber(std::string info, std::string str);
		bool isValidNumber(const std::string &str);
        
};


#endif