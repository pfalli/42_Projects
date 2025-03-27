#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cctype> // std::isdigit
#include <exception>
#include <climits> // For INT_MAX
#include <ctime> // clock()

class PmergeMe {
	private:
		std::vector<int> vec;
		std::deque<int> deq;
		double durationVec;
		double durationDeq;

	public:
	    PmergeMe();
		PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe &other);
	    ~PmergeMe();

		PmergeMe(char **av);
		void printResult(char **av);
		void insertionSort(std::vector<int>& arr, int left, int right);
		void merge(std::vector<int>& arr, int left, int mid, int right);
		void mergeInsertSort(std::vector<int>& arr, int left, int right);

		void insertionSort(std::deque<int>& arr, int left, int right);
		void merge(std::deque<int>& arr, int left, int mid, int right);
		void mergeInsertSort(std::deque<int>& arr, int left, int right);	
};



#endif
