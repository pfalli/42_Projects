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
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main()
{

	std::cout << GREEN "\nBrain class test\n" RESET << std::endl;

    Brain *brain = new Brain();
    Brain *brain1 = new Brain(*brain);
    Brain *brain2 = new Brain();

    *brain2 = *brain1;
	std::cout << std::endl;

    delete brain;
    delete brain1;
    delete brain2;
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------


    std::cout << GREEN "\nAnimal class test" RESET << std::endl;
    std::cout << GREEN "Since Animal class does not have brain, it should not call Brain constructor or destructor\n" RESET << std::endl;
    Animal *animal = new Animal();

    delete animal;

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------


	std::cout << GREEN "\nDeep copies test\n" RESET << std::endl;

	Cat *cat = new Cat(); // Brain created

	std::cout << std::endl;
    cat->getBrain()->addIdea("i hope it works!");
	cat->getBrain()->addIdea("ahhhhhhhh!");
	std::cout << GREEN "this is cat brain idea: " RED << cat->getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << GREEN "this is cat brain idea: " RED << cat->getBrain()->getIdea(1) << RESET << std::endl;

	std::cout << std::endl;
    
	std::cout << std::endl;


	delete cat;

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	// std::cout << GREEN "\nTest from Animal, but Animal doesnt have getBrain() so it doesnt work\n" RESET << std::endl;

    // Animal* animal[8];
	// int i = 0;

    // while (i < 8) {
    //     if (i % 2 == 0)
    //         animal[i] = new Dog();
    //     else
    //         animal[i] = new Cat();
	// 	i++;
    //     std::cout << std::endl;
    // }

	// i--;
	// while (i >= 0)
	// {
	// 	animal[i]->getBrain()->addIdea("wanna eat!");
	// 	std::cout << GREEN "this is cat brain idea: " RED << animal[i]->getBrain()->getIdea(0) << RESET << std::endl;
	// 	i--;
	// }

    // std::cout << "First idea of animal[2]: " << animal[3]->getBrain()->getIdea(2) << std::endl;

  
    
    // for (int i = 0; i < 8; ++i) {
    //     delete animal[i];
    // }

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	std::cout << GREEN "\nTest from Dog and Cat to print Brains\n" RESET << std::endl;

	Cat miaw;
    Dog bau;
	int i = 0;


    miaw.getBrain()->addIdea("I love");
	miaw.getBrain()->addIdea("to stay");
	miaw.getBrain()->addIdea("at home");
	miaw.getBrain()->addIdea("and watching");
	miaw.getBrain()->addIdea("movies!");


    while(i < 5)
    {
        std::cout << GREEN "this is cat brain idea: " RED << miaw.getBrain()->getIdea(i) << RESET << std::endl;
        std::cout << GREEN "this is dog brain idea: " RED << bau.getBrain()->getIdea(i) << RESET << std::endl;
        i++;
    }

    return 0;
}
