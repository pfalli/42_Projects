#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <exception>
#include <cctype>  // for std::isdigit
#include <cstring> // strcmp
#include <sstream> // for std::ostringstream
#include <climits> // for INT_MAX

class BitcoinExchange {
	private:
		void parsing_csv(std::fstream& file);
		std::map<std::string, double> container;
		void checker_csv(std::string date, double exchange_rate);
		int checker_txt(std::string date, double exchange_rate);
		void calculate(std::fstream &file);
		void moltiplication(std::string date, double value);
		void print_container();
	    

	public:
	    BitcoinExchange();
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
	    ~BitcoinExchange();


	
};

void trim(std::string &val);






#endif //
