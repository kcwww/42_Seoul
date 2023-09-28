/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:28:41 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 18:52:23 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
  std::cout << "\x1b[33m""Default constructor called""\x1b[0m" << std::endl;
}

Fixed::Fixed(const Fixed &ref) {
  std::cout << "\x1b[35m""Copy constructor called""\x1b[0m" << std::endl;
  *this = ref;
}

Fixed::~Fixed() {
  std::cout << "\x1b[31m""Destructor called""\x1b[0m" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &ref) {
  std::cout << "\x1b[34m""Copy assignment operator called""\x1b[0m" << std::endl;
  if (this != &ref)
  {
    this->_value = ref.getRawBits();
  }
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "\x1b[32m""getRawBits member function called""\x1b[0m" << std::endl;
  return (this->_value);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "\x1b[32m""setRawBits member function called!""\x1b[0m" << std::endl;
  this->_value = raw;
}
