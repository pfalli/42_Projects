#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    return ;
}

PmergeMe::PmergeMe(char **av) {
    for (int i = 1; av[i] != NULL; ++i) {  // Start from 1 to skip ./main
        for (int j = 0; av[i][j] != '\0'; ++j) {
            if (!std::isdigit(av[i][j]) )
                throw std::out_of_range("Error: input only digits!");
        }
        long value = std::atol(av[i]);
        if (value > INT_MAX) {
            throw std::out_of_range("Error: input exceeds INT_MAX!");
        }
        vec.push_back(std::atoi(av[i]));
        deq.push_back(std::atoi(av[i]));
    }
    clock_t start = clock();
    mergeInsertSort(this->vec, 0, vec.size() - 1);
    clock_t end = clock();
    this->durationVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    mergeInsertSort(this->deq, 0, deq.size() - 1);
    end = clock();
    this->durationDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    return;
}


PmergeMe::PmergeMe(const PmergeMe &other) {
    vec = other.vec;
    return ;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other)
        this->vec = other.vec;
    return *this;
}


PmergeMe::~PmergeMe() {
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void PmergeMe::printResult(char **av) {
    std::cout << "Before: ";
    for (int i = 1; av[i] != NULL; i++) {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken by vector: " << durationVec << " seconds" << std::endl;
    std::cout << "Time taken by vector: " << durationDeq << " seconds" << std::endl;
}

// --------------------------------------------------------------

void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void PmergeMe::insertionSort(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------------------------------------------------------

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    std::size_t i = 0, j = 0, k = left;
    while (i < leftPart.size() && j < rightPart.size()) {
        arr[k++] = (leftPart[i] <= rightPart[j]) ? leftPart[i++] : rightPart[j++];
    }
    while (i < leftPart.size()) arr[k++] = leftPart[i++];
    while (j < rightPart.size()) arr[k++] = rightPart[j++];
}


void PmergeMe::merge(std::deque<int>& arr, int left, int mid, int right) {
    std::deque<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    std::deque<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    std::size_t i = 0, j = 0, k = left;
    while (i < leftPart.size() && j < rightPart.size()) {
        arr[k++] = (leftPart[i] <= rightPart[j]) ? leftPart[i++] : rightPart[j++];
    }
    while (i < leftPart.size()) arr[k++] = leftPart[i++];
    while (j < rightPart.size()) arr[k++] = rightPart[j++];
}

// -----------------------------------------------------
void PmergeMe::mergeInsertSort(std::vector<int>& arr, int left, int right) {
    if (right - left <= 10) {
        insertionSort(arr, left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    mergeInsertSort(arr, left, mid);
    mergeInsertSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void PmergeMe::mergeInsertSort(std::deque<int>& arr, int left, int right) {
    if (right - left <= 10) {
        insertionSort(arr, left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    mergeInsertSort(arr, left, mid);
    mergeInsertSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}