/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/01 17:14:31 by chanwoki         ###   ########.fr       */
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
	atexit(checkLeaks);

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;



 	Animal	*a[4];

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
