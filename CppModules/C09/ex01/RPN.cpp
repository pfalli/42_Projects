#include "RPN.hpp"

RPN::RPN() {
    return ;
}


RPN::RPN(const RPN &other) :_container(other._container), _result(other._result) {
    std::cout << "RPN Copy constructor called" << std::endl;
    return ;
}


RPN &RPN::operator=(const RPN &other) {
    std::cout << "RPN Assignment operator called" << std::endl;
    if (this != &other) {
        this->_result = other._result;
        this->_container = other._container;
    }
    return *this;
}


RPN::~RPN() {
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

bool RPN::isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperator(const std::string &op, int a, int b) {
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/") {
        if (b == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        return a / b;
    }
    throw std::runtime_error("Error in applyOperator.");
    return 0; // Never reach here
}

void RPN::calculator(const std::string &input) {
    std::istringstream tokens(input);
    std::string token;
    int input_num = 0;

    while (tokens >> token) {
        input_num++;
        if (isOperator(token)) {
            if (_container.size() < 2) {
                throw std::out_of_range("Error: wrong input.");
            }
            int b = _container.top();
            _container.pop();
            int a = _container.top();
            _container.pop();
            _container.push(applyOperator(token, a, b));
        } else {
            _container.push(std::atoi(token.c_str())); // Convert string to int
        }
    }
    if (input_num == 1) {
        throw std::out_of_range("Error: wrong input.");
    }
    if (_container.size() != 1) {
        throw std::out_of_range("Error: wrong input.");
    }
    _result = _container.top();
}


int RPN::getResult() {
    return this->_result;
}

std::string intToString(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

std::string generateRandomRPN(int length) {
    std::string rpn;
    std::string operators = "+-*/";
    srand(time(0));

    for (int i = 0; i < 1; ++i) {
        int num = (rand() % 9) + 1;
        rpn += intToString(num) + " ";
    }
    for (int i = 1; i < length - 1; ++i) {
            int num = (rand() % 9) + 1;
            rpn += intToString(num) + " ";
            char op = operators[rand() % operators.size()];
            rpn += op;
            if (i != length - 1) {
                rpn += " ";
            }
    }
    return rpn;
}