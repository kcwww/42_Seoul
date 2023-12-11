/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/11 20:21:44 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog() {
  this->_type = "Dog";
  this->_brain = new Brain();
  std::cout << "\x1b[33m""[Dog]: default constructor has called!""\x1b[0m" << std::endl;
}

Dog::Dog(Dog const &ref) {
  this->_type = ref.getType();
  this->_brain = new Brain(*(ref._brain));
  std::cout << "\x1b[35m""[Dog] Copy constructor has called!""\x1b[0m" << std::endl;
}

Dog::~Dog() {
  delete this->_brain;
  std::cout << "\x1b[31m""[Dog]: destructor has called!""\x1b[0m" << std::endl;
}


Dog&	Dog::operator=(Dog const &ref) {
  if (this != &ref) {
    this->_type = ref.getType();
    delete this->_brain;
    this->_brain = new Brain(*(ref._brain));
    std::cout << "\x1b[34m""[Dog]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[Dog]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}

void  Dog::makeSound() const {
  std::cout << "Wouf Wouf!" << std::endl;
  return ;
}
