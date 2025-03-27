#include <iostream>
#include <string>
#include <stdint.h> // instead of <cstdint> c++11
#include "Serializer.hpp"


int main()
{
	Data case1;
	case1.num = 10; // 0
	case1.str = "Piero"; // ""

	uintptr_t tmp = Serializer::serialize(&case1);
	Data *deserialized = Serializer::deserialize(tmp);

	std::cout << "Original address: " << &case1 << std::endl;
    std::cout << "Deserialized address: " << deserialized << " (should be the same)" << std::endl;
    std::cout << "Original num: " << case1.num << std::endl;
    std::cout << "Deserialized num: " << deserialized->num << std::endl;
    std::cout << "Original str: " << case1.str << std::endl;
    std::cout << "Deserialized str: " << deserialized->str << std::endl;


	return (0);
}
