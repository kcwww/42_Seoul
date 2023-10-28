/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/28 20:38:30 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "Brain.hpp"

#include <stdlib.h>


int main( void )
{
	// Exercice example
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	//const AAnimal* animal = new AAnimal();

	dog->makeSound();
	cat->makeSound();


	delete dog;
	delete cat;

}
