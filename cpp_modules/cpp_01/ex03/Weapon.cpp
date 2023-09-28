/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:03:38 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 12:59:51 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
  std::cout << "Weapon constructor called" << std::endl;
  return ;
}

Weapon::~Weapon(void)
{
  std::cout << "Weapon destructor called" << std::endl;
  return ;
}

std::string const &Weapon::getType(void)
{
  return (this->_type);
}

void	Weapon::setType(std::string type)
{
  this->_type = type;
  return ;
}
