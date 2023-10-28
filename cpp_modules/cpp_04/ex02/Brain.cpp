/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:48:41 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/01 17:07:55 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"

Brain::Brain() {
  std::cout << "\x1b[33m""[Brain]: default constructor has called!""\x1b[0m" << std::endl;
}

Brain::Brain(Brain const &ref) {
  for (int i = 0; i < 100; i++)
    this->_ideas[i] = ref.getIdeas()[i];
  std::cout << "\x1b[35m""[Brain]: Copy constructor has called!""\x1b[0m" << std::endl;
}

Brain::~Brain() {
  std::cout << "\x1b[31m""[Brain]: destructor has called!""\x1b[0m" << std::endl;
}


std::string const *Brain::getIdeas() const {
  return (this->_ideas);
}

Brain&	Brain::operator=(Brain const &ref) {
  if (this != &ref) {
    for (int i = 0; i < 100; i++)
      this->_ideas[i] = ref.getIdeas()[i];
    std::cout << "\x1b[34m""[Brain]: assign operator has called!""\x1b[0m" << std::endl;
  }
  else
    std::cout << "\x1b[34m""[Brain]: assign operator with same instance!""\x1b[0m" << std::endl;
  return (*this);
}
