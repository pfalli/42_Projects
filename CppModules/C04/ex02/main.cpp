/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:20:07 by pfalli            #+#    #+#             */
/*   Updated: 2024/11/20 12:20:07 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main(void)
{
    // Animal *animal = new Animal();

    // delete animal;

    // Animal test;

    Animal *dog = new Dog();
    Animal *cat = new Cat();

    // makesound 

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;
}


// int main(void)
// {
//     std::cout << GREEN << "Creating Dog and Cat objects..." << RESET << std::endl;
//     Animal *dog = new Dog();
//     Animal *cat = new Cat();

//     std::cout << GREEN << "Testing makeSound() method..." << RESET << std::endl;
//     dog->makeSound();
//     cat->makeSound();

//     std::cout << GREEN << "Testing getType() method..." << RESET << std::endl;
//     std::cout << "Dog type: " << dog->getType() << std::endl;
//     std::cout << "Cat type: " << cat->getType() << std::endl;

//     std::cout << GREEN << "Deleting Dog and Cat objects..." << RESET << std::endl;
//     delete dog;
//     delete cat;
// 	std::cout << std::endl;

//     std::cout << GREEN << "Creating array of Animal pointers..." << RESET << std::endl;
//     Animal *animals[4];
//     for (int i = 0; i < 2; ++i) {
//         animals[i] = new Dog();
//     }
//     for (int i = 2; i < 4; ++i) {
//         animals[i] = new Cat();
//     }

//     std::cout << GREEN << "Testing makeSound() method on array..." << RESET << std::endl;
//     for (int i = 0; i < 4; ++i) {
//         animals[i]->makeSound();
//     }

//     std::cout << GREEN << "Deleting array of Animal pointers..." << RESET << std::endl;
//     for (int i = 0; i < 4; ++i) {
//         delete animals[i];
//     }
// 	std::cout << std::endl;

//     std::cout << GREEN << "Testing deep copy of Cat object..." << RESET << std::endl;
//     Cat originalCat;
//     Cat copiedCat = originalCat;

//     std::cout << GREEN << "Testing makeSound() method on copied Cat..." << RESET << std::endl;
//     copiedCat.makeSound();

//     std::cout << GREEN << "Testing getBrain() method on original and copied Cat..." << RESET << std::endl;
//     std::cout << "Original Cat brain address: " << originalCat.getBrain() << std::endl;
//     std::cout << "Copied Cat brain address: " << copiedCat.getBrain() << std::endl;

//     std::cout << GREEN << "Testing assignment operator on Cat object..." << RESET << std::endl;
//     Cat anotherCat;
//     anotherCat = originalCat;

//     std::cout << GREEN << "Testing makeSound() method on assigned Cat..." << RESET << std::endl;
//     anotherCat.makeSound();

//     std::cout << GREEN << "Testing getBrain() method on assigned Cat..." << RESET << std::endl;
//     std::cout << "Assigned Cat brain address: " << anotherCat.getBrain() << std::endl;

//     return 0;
// }