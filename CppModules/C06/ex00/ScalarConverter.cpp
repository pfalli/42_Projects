#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Default constructor called" << std::endl;
    return ;
}


ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return ;
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}


ScalarConverter::~ScalarConverter() {
    std::cout << "Default destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

int getType(std::string input) {
    if (input.length() == 1 && !isdigit(input.at(0))) { // to access first char
        return CHAR;
    }
    if (input == "nan" || input == "-inf" || input == "-inff" || input == "+inf" || input == "+inff") {
        return PSEUDO;
    }
    for (size_t i = 0; i < input.length(); i++) {
        if (!isdigit(input.at(i)) && input.at(i) != 'f' && input.at(i) != '+' && input.at(i) != '-' && input.at(i) != '.') {
            return FALSE;
        }
        if (i != 0 && (input.at(i) == '+' || input.at(i) == '-')) {
            return FALSE;
        }
    }
    if (std::count(input.begin(), input.end(), '.') > 1 || std::count(input.begin(), input.end(), 'f') > 1) {
        return FALSE; // too many '.' or 'f'
    }
    if (std::count(input.begin(), input.end(), '.') == 1 && input.at(input.length() - 1) == 'f' && input.at(0) != 'f') {
        return FLOAT;
    }
    if (std::count(input.begin(), input.end(), '.') == 1) {
        return DOUBLE;
    }
    return INT;
}


void printing(char c, int num, float f, double d, bool is_valid, bool int_limit) {
    if (num > 32 && num < 127) { // CHAR cases
        std::cout << "char: " << c << std::endl;
        if (int_limit == false) {
            std::cout << "int: " << num << std::endl;
        }
        else {
            std::cout << "int: Non displayable" << std::endl;
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (is_valid == true) {
        std::cout << "char: Non displayable" << std::endl;
        if (int_limit == false) {
            std::cout << "int: " << num << std::endl;
        }
        else {
            std::cout << "int: Non displayable" << std::endl;
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl; //ensure that the float output has one decimal place
        std::cout << "double: " << d << std::endl;
    }
    else { // PSEUDO cases
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}


void handle_int(int num) {
    char conv_char = static_cast<char>(num); // static_cast because are related Types
    float conv_float = static_cast<float>(num);
    double conv_double = static_cast<double>(num);
    printing(conv_char, num, conv_float, conv_double, true, false);
}

void handle_char(char c) {
    int conv_int = static_cast<int>(c);
    float conv_float = static_cast<float>(c);
    double conv_double = static_cast<double>(c);
    printing(c, conv_int, conv_float, conv_double, true, false);
}

void handle_float(float f) {
    int int_limit = 0;
    int conv_int = 0;
    if (f > INT_MAX || f < INT_MIN)
        int_limit = true;
    else {
        int_limit = false;
        conv_int = static_cast<int>(f);
    }
    char conv_char = static_cast<char>(f);
    double conv_double = static_cast<double>(f);
    printing(conv_char, conv_int, f, conv_double, true, int_limit);
}

void handle_double(double d) {
    int conv_int = static_cast<int>(d);
    char conv_char = static_cast<char>(d);
    float conv_float = static_cast<float>(d);
    printing(conv_char, conv_int, conv_float, d, true, false);
}

void handle_pseudo(std::string str) {
    float conv_float = static_cast<float>(atof(str.c_str()));
	double conv_double = static_cast<double>(conv_float);
	char conv_char = static_cast<char>(conv_float);
	int conv_int = static_cast<int> (conv_float);
    printing(conv_char, conv_int, conv_float, conv_double, false, false);
}


void ScalarConverter::convert(std::string input) {
    if (input.empty()) {
        std::cout << "Input is empty!" << std::endl;
        return ;
    }
    int type = getType(input);
    std::cout << type << std::endl;
    long int temp = atol(input.c_str());
    if (type != 1 && (temp > INT_MAX || temp < INT_MIN )) {
        type = FLOAT;
    }
    switch(type) {
        case 1:
            std::cout << "Error: incorrect input!" << std::endl;
            break;
        case 2:
            handle_int(std::atoi(input.c_str())); // converting ascii string to INT
            break;
        case 3:
            handle_char(input.at(0));
            break;
        case 4:
            handle_float(std::atof(input.c_str()));
            break;
        case 5:
            handle_double(std::atof(input.c_str()));
            break;
        case 6:
            handle_pseudo(input);
            break;
        
    }
}