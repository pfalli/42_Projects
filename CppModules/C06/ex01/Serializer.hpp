#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data { // By default, the members of a struct are public.
	int num;
	std::string str;
};

class Serializer {
	private:
	    Serializer();
		Serializer(const Serializer& other);
        Serializer &operator=(const Serializer &other);
	    ~Serializer();
	    // Add your private members here

	public:
		static uintptr_t serialize(Data* ptr); // This means it can be called without creating an instance of Serializer
		static Data* deserialize(uintptr_t raw);


};

#endif //
