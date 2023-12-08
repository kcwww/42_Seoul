/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:28:41 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/08 13:15:05 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref) {
  std::cout << "Copy constructor called" << std::endl;
  *this = ref;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &ref) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &ref)
  {
    this->_value = ref.getRawBits();
  }
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_value);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called!" << std::endl;
  this->_value = raw;
}
