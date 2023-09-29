/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:50:38 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 12:59:14 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
  return ;
}

Point::Point(Point const & src) : _x(src.getX()), _y(src.getY())
{
  return ;
}

Point::~Point(void)
{
  return ;
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
  return ;
}

Fixed const Point::getX(void) const
{
  return this->_x;
}

Fixed const Point::getY(void) const
{
  return this->_y;
}

Point& Point::operator=(const Point& obj)
{
  if (this != &obj)
  {
    const_cast<Fixed&>(this->_x) = obj.getX();
    const_cast<Fixed&>(this->_y) = obj.getY();
  }
  return *this;
}
