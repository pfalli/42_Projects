#include "MutantStack.hpp"

void printStack(std::stack<int>& s) { // Recursive 
    if (s.empty())
        return;
    int top = s.top();
    s.pop();
    printStack(s);
    std::cout << top << " "; // Print after stack is empty
    s.push(top);
}

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size after pop:  " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    printStack(mstack);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "\nbegin: " << *it << std::endl;
    std::cout << "end: " << *ite << std::endl;
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack); // it doesnt have begin() and end()
    MutantStack<int> newstack(mstack); // it has defined
    for (MutantStack<int>::iterator op = newstack.begin(); op != newstack.end(); ++op) {
        std::cout << *op << std::endl;
    }
    // for (MutantStack<int>::iterator op = s.begin(); op != s.end(); ++op) {
    //     std::cout << *op << std::endl;
    // }
    // printStack(s);
    std::cout << std::endl;

    return 0;
}