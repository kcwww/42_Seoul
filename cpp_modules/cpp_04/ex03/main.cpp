/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:12:56 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:11:26 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Amateria.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());   // Ice stored in materia[0]
    src->learnMateria(new Cure());  // Cure stored in materia[1]
    ICharacter* me = new Character("me");
    AMateria* tmp;
    AMateria* tmp2;
    tmp = src->createMateria("ice");    // returns a new Ice materia
    me->equip(tmp); // equip in inventory[0]
    tmp2 = src->createMateria("cure");  // returns a new Cure materia
    me->equip(tmp2); // equip in inventory[1]
    //me->unequip(0); // unequip inventory[0]
    // me->unequip(1); // unequip inventory[1]
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);   // use inventory[0] on bob
    me->use(1, *bob);   // use inventory[1] on bob
    delete bob;
    delete me;
    delete src;
    //delete tmp;
    // delete tmp2;
    return 0;
}
