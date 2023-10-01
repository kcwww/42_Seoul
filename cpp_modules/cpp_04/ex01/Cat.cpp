/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/01 14:44:59 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

Cat::Cat() {
  this->_type = "Cat";
  this->_brain = new Brain();
  std::cout << "\x1b[33m""[Cat]: default constructor has called!""\x1b[0m" << std::endl;
}

Cat::Cat(Cat const &ref) {
  *this = ref;
  this->_brain = new Brain(*ref.getBrain());
  std::cout << "\x1b[35m""Copy constructor has called!""\x1b[0m" << std::endl;
}

Cat::~Cat() {
  delete this->_brain;
  std::cout << "\x1b[31m""[Cat]: destructor has called!""\x1b[0m" << std::endl;
}

Brain *Cat::getBrain() const {
  return (this->_brain);
}

Cat&	Cat::operator=(Cat const &ref) {
  if (this != &ref) {
    this->_type = ref.getType();
    delete this->_brain;
    this->_brain = new Brain(*ref.getBrain());
    std::cout << "\x1b[34m""[Cat]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[Cat]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}

void  Cat::makeSound() const {
  std::cout << "Miaou Miaou!" << std::endl;
  return ;
}
