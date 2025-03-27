#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <ctime>

class RPN {
	private:
		std::stack<int> _container;
		int _result;

	public:
	    RPN();
		RPN(const RPN& other);
        RPN &operator=(const RPN &other);
	    ~RPN();

		int applyOperator(const std::string &op, int a, int b);
		bool isOperator(const std::string &token);
		void calculator(const std::string &input);
		int getResult();
	
};

std::string intToString(int num);
std::string generateRandomRPN(int length);

#endif //
