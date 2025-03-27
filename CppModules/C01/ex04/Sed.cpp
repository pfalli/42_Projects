/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:29:40 by pfalli            #+#    #+#             */
/*   Updated: 2024/11/25 18:55:36 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename) : _inFile(filename){ // initializer list
    this->_outFile = this->_inFile + ".replace";
}

Sed::~Sed() {
    // Destructor implementation
}


void Sed::replace(std::string oldstr, std::string newstr) {
    std::ifstream ifs(this->_inFile.c_str()); // ifstream need a const string READ
    if (!ifs.is_open()) { // boolean
        std::cerr << "Error opening file: " << this->_inFile << std::endl;
        exit(1);
    }
    else {
        std::string content;
        if (std::getline(ifs, content, '\0')) { // delimiter
            std::ofstream ofs(this->_outFile.c_str()); // ofstream need a const string WRITE
            size_t pos = content.find(oldstr);
            while (pos != std::string::npos) {
                content.erase(pos, oldstr.length());
                content.insert(pos, newstr);
                pos = content.find(oldstr); // it's needed to continue searching other words or "string"
            }
            ofs << content; // write
            ofs.close();
        } else {
            std::cerr << "Empty file found." << std::endl;
        }
        ifs.close();
    } 
}
