/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:30:51 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/08 13:32:49 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
  return ;
}

Fixed::Fixed(Fixed const & src) {
  *this = src;
  return ;
}

Fixed::~Fixed(void) {
  return ;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
  if (this != &rhs)
    this->_fixedPointValue = rhs.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
  this->_fixedPointValue = raw;
  return ;
}

Fixed::Fixed(int const n) {
  this->_fixedPointValue = n << this->_fractionalBits;
  return ;
}

Fixed::Fixed(float const n) {
  this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
  return ;
}

float Fixed::toFloat(void) const {
  return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
  return this->_fixedPointValue >> this->_fractionalBits;
}

bool Fixed::operator>(Fixed const & rhs) const {
  return this->_fixedPointValue > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) const {
  return this->_fixedPointValue < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) const {
  return this->_fixedPointValue >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) const {
  return this->_fixedPointValue <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) const {
  return this->_fixedPointValue == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) const {
  return this->_fixedPointValue != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const & rhs) const {
  Fixed result(this->toFloat() + rhs.toFloat());
  return result;
}

Fixed Fixed::operator-(Fixed const & rhs) const {
  Fixed result(this->toFloat() - rhs.toFloat());
  return result;
}

Fixed Fixed::operator*(Fixed const & rhs) const {
  Fixed result(this->toFloat() * rhs.toFloat());
  return result;
}

Fixed Fixed::operator/(Fixed const & rhs) const {
  Fixed result(this->toFloat() / rhs.toFloat());
  return result;
}

Fixed & Fixed::operator++(void) {
  this->_fixedPointValue += 1;
  return *this;
}

Fixed & Fixed::operator--(void) {
  this->_fixedPointValue -= 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return tmp;
}

Fixed & Fixed::min(Fixed & a, Fixed & b) {
  return (a < b) ? a : b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
  return (a > b) ? a : b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
  return (a < b) ? a : b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
  return (a > b) ? a : b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
  o << rhs.toFloat();
  return o;
}
