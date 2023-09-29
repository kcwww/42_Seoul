/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:14 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:17:02 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"

Animal::Animal() {
  std::cout << "\x1b[33m""[Animal]: default constructor has called!""\x1b[0m" << std::endl;
}

Animal::Animal(Animal const &ref) {
  *this = ref;
  std::cout << "\x1b[35m""[Animal]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Animal::~Animal() {
  std::cout << "\x1b[31m""[Animal]: destructor has called!""\x1b[0m" << std::endl;
}

Animal&	Animal::operator=(Animal const &ref) {
  if (this != &ref) {
    std::cout << "\x1b[34m""[Animal]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[Animal]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}
