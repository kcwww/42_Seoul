/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:14 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/11 20:29:59 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
  std::cout << "\x1b[33m""[AAnimal]: default constructor has called!""\x1b[0m" << std::endl;
}

AAnimal::AAnimal(AAnimal const &ref) : _type(ref.getType()) {
  std::cout << "\x1b[35m""[AAnimal]: Copy constructor has called!""\x1b[0m" << std::endl;
}

AAnimal::~AAnimal() {
  std::cout << "\x1b[31m""[AAnimal]: destructor has called!""\x1b[0m" << std::endl;
}

AAnimal&	AAnimal::operator=(AAnimal const &ref) {
  if (this != &ref) {
    this->_type = ref.getType();
    std::cout << "\x1b[34m""[AAnimal]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[AAnimal]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}

std::string	AAnimal::getType() const {
  return (this->_type);
}
