#include "Array.hpp"

template <typename T>
void printArray(Array<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Array<std::string> empty;
    Array<std::string> non_empty(10);

    if (empty.size() == 0) {
        std::cout << "\nThe array 'empty' is empty.\n" << std::endl;
    } else {
        std::cout << "The array 'empty' is not empty." << std::endl;
        printArray(empty);
    }
    try {
        non_empty[5] = "hello";
        non_empty[2] = "...";
        non_empty[8] = "123";
        non_empty[22] = "world";
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    printArray(non_empty);
    std::cout << "\nSize of the array: " << non_empty.size() << std::endl;
    return 0;
}
