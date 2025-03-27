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
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog(); // polymorphism, it uses the pointer to point to a derived class
    const Animal* i = new Cat();
    const WrongAnimal* z = new WrongCat();

	std::cout << std::endl;
    std::cout << j->getType() << " getType of" <<  std::endl; // so the j->getType() will call the overridden methods in the Dog class.
    std::cout << i->getType() << " getType of" << std::endl;
	std::cout << std::endl;
    i->makeSound();
    j->makeSound();
	std::cout << std::endl;
    meta->makeSound();
	std::cout << std::endl;

	std::cout << GREEN "Testing Wrong Animal\n" RESET << std::endl;
    std::cout << z->getType() << " getType of" << std::endl;
    z->makeSound(); // bird sound

	std::cout << GREEN "\nTesting copy animal\n" RESET << std::endl;
    const Dog* originalDog = new Dog();
    const Dog* copiedDog = new Dog(*originalDog);
    std::cout << copiedDog->getType() << " getType of" << std::endl;
    copiedDog->makeSound();
	std::cout << std::endl;


    delete meta;
    delete j;
    delete i;
    delete z;
    return 0;
}

// int main() {
//     const WrongAnimal* elephant = new WrongAnimal();
//     const WrongAnimal* mouse = new WrongCat();

//     std::cout << elephant->getType() << " " <<  std::endl;
//     std::cout << mouse->getType() << " " <<  std::endl;
//     elephant->makeSound();
//     mouse->makeSound();

//     delete elephant;
//     delete mouse;

//     return 0;

// }