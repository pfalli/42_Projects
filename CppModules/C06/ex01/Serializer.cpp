#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer Default constructor called" << std::endl;
    return ;
}


Serializer::Serializer(const Serializer &other) {
    std::cout << "Serializer Copy constructor called" << std::endl;
    *this = other;
    return ;
}


Serializer &Serializer::operator=(const Serializer &other) {
    std::cout << "Serializer Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}


Serializer::~Serializer() {
    std::cout << "Serializer Default destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

uintptr_t Serializer::serialize( Data *ptr )
{
	return reinterpret_cast<uintptr_t>(ptr); // reinterpret_cast because are unrelated Types
}

Data* Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data*>(raw);
}