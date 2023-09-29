/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:32 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 18:02:13 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
  std::cout << "\x1b[33m""[WrongAnimal]: default constructor has called!""\x1b[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref) {
  *this = ref;
  std::cout << "\x1b[35m""[WrongAnimal]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "\x1b[31m""[WrongAnimal]: destructor has called!""\x1b[0m" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &ref) {
  if (this != &ref) {
    this->_type = ref.getType();
    std::cout << "\x1b[34m""[WrongAnimal]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[WrongAnimal]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}

void	WrongAnimal::makeSound() const {
  std::cout << "if you see this message, you are in the wrong class!" << std::endl;
  return ;
}

std::string	WrongAnimal::getType() const {
  return (this->_type);
}
