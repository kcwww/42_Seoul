/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:35 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:16:12 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat() {
  std::cout << "\x1b[33m""[WrongCat]: default constructor has called!""\x1b[0m" << std::endl;
}

WrongCat::WrongCat(WrongCat const &ref) {
  *this = ref;
  std::cout << "\x1b[35m""[WrongCat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "\x1b[31m""[WrongCat]: destructor has called!""\x1b[0m" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const &ref) {
  if (this != &ref) {
    //compose deep-copy with your own class!
    std::cout << "\x1b[34m""[WrongCat]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[WrongCat]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}
