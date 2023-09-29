/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:41:26 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 11:55:25 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::Fixed(int const value)
{
  std::cout << "Int constructor called" << std::endl;
  this->_value = value << this->_bits;
}

Fixed::Fixed(float const value)
{
  std::cout << "Float constructor called" << std::endl;
  this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
    this->_value = rhs.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const
{
  return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
  this->_value = raw;
}

float Fixed::toFloat(void) const
{
  return ((float)this->_value / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
  return (this->_value >> this->_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
  o << rhs.toFloat();
  return (o);
}
