#include "whatever.hpp"
#include <iostream>

int main( void ) {
    int a = 2;
    int b = 3;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    // test it with float

    std::string c = "Hello";
    std::string d = "Woo";
    std::cout << "Before swap: a = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap: a = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}


// int main( void ) {
//     int a = 2;
//     int b = 3;
//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     std::string c = "chaine1";
//     std::string d = "chaine2";
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// }
