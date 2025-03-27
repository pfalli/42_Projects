#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename anytype>
void swap(anytype &a, anytype &b) {
    anytype tmp = a;
    a = b;
    b = tmp;
}

template <typename anytype>
anytype max(anytype a, anytype b) {
    if (a > b)
        return a;
    else
        return b;
}

template <typename anytype>
anytype min(anytype a, anytype b) {
    if (a < b)
        return a;
    else
        return b;
}


#endif // WHATEVER_HPP