/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:32 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:16:17 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
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
    //compose deep-copy with your own class!
    std::cout << "\x1b[34m""[WrongAnimal]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[WrongAnimal]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}
