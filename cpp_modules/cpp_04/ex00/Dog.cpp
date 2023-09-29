/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:40:47 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog() {
  this->_type = "Dog";
  std::cout << "\x1b[33m""[Dog]: default constructor has called!""\x1b[0m" << std::endl;
}

Dog::Dog(Dog const &ref) {
  *this = ref;
  std::cout << "\x1b[35m""[Dog]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Dog::~Dog() {
  std::cout << "\x1b[31m""[Dog]: destructor has called!""\x1b[0m" << std::endl;
}

Dog&	Dog::operator=(Dog const &ref) {
  if (this != &ref) {
    //compose deep-copy with your own class!
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
