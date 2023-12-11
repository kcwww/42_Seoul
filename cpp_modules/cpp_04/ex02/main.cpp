/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/11 20:35:54 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "Brain.hpp"




int main()
{
    std::cout << std::endl << "***Test virtual destructor" << std::endl;

    const int arrSize = 6;
    const AAnimal* animals[arrSize];

    for(int k = 0; k < arrSize/2; ++k) {
        animals[k] = new Dog();
    }
    for(int k = arrSize/2; k < arrSize; ++k) {
        animals[k] = new Cat();
    }
    for(int k = 0; k < arrSize; ++k) {
        delete animals[k];
    }

		//const AAnimal* meta = new AAnimal();
    std::cout << std::endl << "***Test deep copy" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    return 0;
}
