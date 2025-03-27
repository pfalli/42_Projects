#include "easyfind.hpp"

template <typename T>
void print_vector(std::vector<T> vec) {
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main(void) {
	std::vector<int> obj1;
	obj1.push_back(5);
	obj1.push_back(10);
	obj1.push_back(333);
	obj1.push_back(666);
	print_vector(obj1);

	try {
		easyfind(obj1, 3);
		std::cout << "Input found!" <<  std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n";

	return 0;
}



	// std::vector<std::string> obj2;
	// obj2.push_back("hello");
	// obj2.push_back(" piero");
	// obj2.push_back(":");
	// obj2.push_back("  666");
	// print_vector(obj2);

	// try {
	// 	easyfind(obj2, "666");
	// 	std::cout << "Input found!" <<  std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }