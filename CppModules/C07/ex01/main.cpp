#include "iter.hpp"
#include <iostream>

int main() {
    int array[] = {6, 15, 2};
    int length = sizeof(array) / sizeof(array[0]);

    iter(array, length, function); // iter(&array, length, function);
    return 0;
}


// int main()
// {
//     int arr_int[3] = {1,9,3}; 
//     iter(arr_int, 3, print_elements);
    
//     float arr_float[3] = {1.00000f, 234.134, .2f};
//     iter(arr_float, 3, print_elements);
    
//     std::string arr_str[3] = {"testing", "that", "programm"};
//     iter(arr_str, 3, print_elements);

//     std::string rel = "aha";
//     print_elements(rel);
// }