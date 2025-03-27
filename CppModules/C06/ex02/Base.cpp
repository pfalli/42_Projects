#include "Base.hpp"

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

Base * generate(void) {
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL; // safety in case rand() is out of range
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) // for downcasting in polymorphic classes hierarchy
        std::cout << "The identified type is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The identified type is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The identified type is C" << std::endl;
    else
        std::cout << "Type out of range" << std::endl;
}

void identify(Base& p) {
    try {
        if (dynamic_cast<A*>(&p))
            std::cout << "The identified type is A" << std::endl;
        else if (dynamic_cast<B*>(&p))
            std::cout << "The identified type is B" << std::endl;
        else if (dynamic_cast<C*>(&p))
            std::cout << "The identified type is C" << std::endl;
        else
            std::cout << "Type out of range" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << " Unknown type." << std::endl;
    }
}

// void identify(Base& p) {
//     try {
//         A& a = dynamic_cast<A&>(p);
//         std::cout << "The identified type is A" << std::endl;
//         return;
//     } catch (const std::bad_cast&) {}

//     try {
//         B& b = dynamic_cast<B&>(p);
//         std::cout << "The identified type is B" << std::endl;
//         return;
//     } catch (const std::bad_cast&) {}

//     try {
//         C& c = dynamic_cast<C&>(p);
//         std::cout << "The identified type is C" << std::endl;
//         return;
//     } catch (const std::bad_cast&) {}

//     std::cout << "Type is unknown. Identification failed." << std::endl;
// }