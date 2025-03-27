#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <climits>
#include <algorithm>

# define FALSE 1;
# define INT 2;
# define CHAR 3;
# define FLOAT 4;
# define DOUBLE 5;
# define PSEUDO 6;



class ScalarConverter {
	private:
	    ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter &other);
	    ~ScalarConverter();

	public:

		static void convert(std::string str);
	
};

#endif //
