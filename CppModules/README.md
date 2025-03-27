# C++ Modules at 42 School

## Overview

The C++ modules at 42 School are designed to provide a deep understanding of C++ programming, covering both fundamental and advanced concepts:

Classes, Namespaces, Overloading, “const” and “static” keywords, Inheritance, Dynamic Memory Allocation with “new” and “delete”, Switch Statements, Arrays of Function Pointers (instead of if/else blocks), References, Streams, Exceptions, Templates, Type Casting, Polymorphism, Containers, and Iterators.

## Module Summaries

### C++ Module 00: Basics of C++

- **Introduction to C++**: Understanding the syntax and structure of C++ programs.
- **Data Types**: Primitive data types, variables, and constants.
- **Operators**: Arithmetic, relational, logical, and bitwise operators.
- **Control Structures**: Conditional statements (`if`, `else`, `switch`) and loops (`for`, `while`, `do-while`).
- **Functions**: Function declaration, definition, and overloading.
- **Namespaces**: Using namespaces to avoid name conflicts.

### C++ Module 01: Memory Allocation and References

- **Pointers**: Understanding pointers, pointer arithmetic, and pointer to pointer.
- **References**: Using references as an alternative to pointers.
- **Dynamic Memory Allocation**: Using `new` and `delete` for dynamic memory management.
- **Arrays and Strings**: Handling arrays and C-style strings.
- **Function Pointers**: Using pointers to functions for callback mechanisms.

### C++ Module 02: Ad-hoc Polymorphism, Operators Overloading, and Orthodox Canonical Form

- **Ad-hoc Polymorphism**: Function overloading and operator overloading.
- **Orthodox Canonical Form**: Implementing constructors, destructors, copy constructors, and assignment operators.
- **Operator Overloading**: Overloading operators to work with user-defined types.

### C++ Module 03: Inheritance

- **Inheritance**: Understanding base and derived classes.
- **Access Specifiers**: `public`, `protected`, and `private` inheritance.
- **Constructors and Destructors**: Order of constructor and destructor calls in inheritance.
- **Polymorphism**: Using `virtual` functions to achieve runtime polymorphism.

### C++ Module 04: Abstract Classes and Interfaces

- **Abstract Classes**: Defining abstract classes with `pure virtual functions`.
- **Interfaces**: Using abstract classes to define interfaces.
- **Multiple Inheritance**: Handling multiple inheritance and the `diamond` problem.
- **Virtual Destructors**: Ensuring proper cleanup of derived class objects.

### C++ Module 05: Repetition and Exceptions

- **Exception Handling**: Using `try`, `catch`, and `throw` for error handling.
                        `throw`: `out_of_range(""), logic_error(""), runtime_error("");`
- **Standard Exceptions**: Using `std::exception`, `what()`.
- **Custom Exceptions**: Creating and using custom exception classes (inside derived classes `Robotomy.hpp`).
- **Acces Specifiers**: Using `friend` method.

### C++ Module 06: C++ Casts

- **C++ Casts**: Understanding and using:
`dynamic_cast` is used for safe downcasting in polymorphic classes, so it checks if the pointer is pointing to a derived class;
`static_cast` converts related types(example: static_cast<float>(int i));
`reinterpret_cast` is used for low-level casting between "unrelated types" (like pointer to int);
`const_cast` remove the const;
- **Calling a derived from pointer of Base**: `void identify(Base* p);`

### C++ Module 07: Templates

- **Templates**: allow you to write functions and classes that work with any data type.
- **Example**: `template <typename T>, class Box {}`: typename is a placeholder for a specific data type;
- **Template Specialization**: `template <>,`
                                `class Box<int> {}`
                              if you instance Box<int> Piero, it accesses the specialized template than the typename Template;
- **Class Template**: `template <typename T>,`
                        `Array<T>::Array() {}`.

### C++ Module 08: Templated Containers and Algorithms

- **STL**: (Standard Template Library) is a collection of container classes, iterators, algorithms, and function objects
- **Containers**: are data structures used to store collections of elements. (STL) containers like `vector`, `list`, `map`, etc.
- **Iterators**: used to traverse and manipulate the elements of a container, like "pointer" to the elements of a container: `auto`, `::iterator`;
You obtain iterators using member functions of the container `.begin()`, `end()`;
- **Traversing a Container**: `for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)`.
- **Container Adaptor**:  `std::stack`:  is a container with Last-In-First-Out (LIFO) not iterable, elements accessible using `top, push, pop`. Instead if you need to iterate through elements, you should use the underlying container (std::vector or std::deque);
You don’t need direct access to the elements or iteration like vector do.

### C++ Module 09: Memory Management and Smart Pointers

`std::stringstream` is used to parse a string into individual components

`std::getline` can take an optional third parameter which specifies the delimiter character. By default, std::getline uses the newline character ('\n') as the delimiter, but you can specify a different delimiter if needed.

`std::map<...., ....>`: is using iterator->first, iterator->second;

- **Merge-Insert sort algortihm**:

Why is This Efficient?

    Pairs reduce unnecessary comparisons early.
    The base sequence is sorted optimally.
    Insertion uses binary search, minimizing the number of comparisons.
    
          - It is not commonly used in practice due to its complexity but is significant in 
            theoretical computer science because it achieves near-optimal comparison efficiency.

          - It is useful in settings where comparisons are very expensive, such as when sorting 
            elements that require computationally expensive comparisons.
    