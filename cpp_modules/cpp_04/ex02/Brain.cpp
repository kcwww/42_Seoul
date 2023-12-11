/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:48:41 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/11 20:14:31 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"

Brain::Brain() {
  std::cout << "\x1b[33m""[Brain]: default constructor has called!""\x1b[0m" << std::endl;
}

Brain::Brain(Brain const &ref) {
  for (unsigned int i = 0; i < _ideasSize; i++)
    this->_ideas[i] = ref._ideas[i];
  std::cout << "\x1b[35m""[Brain]: Copy constructor has called!""\x1b[0m" << std::endl;
}

Brain::~Brain() {
  std::cout << "\x1b[31m""[Brain]: destructor has called!""\x1b[0m" << std::endl;
}

Brain&	Brain::operator=(Brain const &ref) {
  if (this != &ref) {
    for (unsigned int i = 0; i < _ideasSize; i++)
      this->_ideas[i] = ref._ideas[i];
    std::cout << "\x1b[34m""[Brain]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[Brain]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}
