/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:06:14 by pfalli            #+#    #+#             */
/*   Updated: 2024/10/25 11:06:14 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
    #define HARL_HPP

#include <iostream>
#include <string>

class Harl {
    public:
        Harl();
        ~Harl();
        void    complain( std::string level );

    private:
        void    _debug(void);
        void    _info(void);
        void    _warning(void);
        void    _error(void);

};

#endif