/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:40:54 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

Cat::Cat() {
  this->_type = "Cat";
  std::cout << "\x1b[33m""[Cat]: default constructor has called!""\x1b[0m" << std::endl;
}

Cat::Cat(Cat const &ref) {
  *this = ref;
  std::cout << "\x1b[35m""[Cat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Cat::~Cat() {
  std::cout << "\x1b[31m""[Cat]: destructor has called!""\x1b[0m" << std::endl;
}

Cat&	Cat::operator=(Cat const &ref) {
  if (this != &ref) {
    //compose deep-copy with your own class!
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
