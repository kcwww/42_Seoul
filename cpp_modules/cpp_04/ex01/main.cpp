/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 18:29:52 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "Brain.hpp"

#include <stdlib.h>

void	checkLeaks()
{
	system("leaks Animal");
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

 	Animal	*a[4];

	Animal *abc = new Dog();
	Animal *def = new Cat();

	Animal *ggg = abc;

	ggg->makeSound();
	def->makeSound();

	delete def;
	delete ggg;

	atexit(checkLeaks);
	for(int i=0; i<4; i++) {
		if (i < 2) {
			a[i] = new Cat();
		}
		else {
			a[i] = new Dog();
		}
	}
	for(int i=0; i<4; i++) {
		a[i]->makeSound();
	}

	for(int i=0; i<4; i++) {
		delete a[i];
	}

	return 0;
}
