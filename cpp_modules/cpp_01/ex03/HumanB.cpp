/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:03:31 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 12:58:09 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
  std::cout << "HumanB constructor called" << std::endl;
  return ;
}

HumanB::~HumanB(void)
{
  std::cout << "HumanB destructor called" << std::endl;
  return ;
}

void	HumanB::attack(void)
{
  if (this->_weapon)
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
  else
    std::cout << this->_name << " attacks with their bare hands" << std::endl;
  return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
  this->_weapon = &weapon;
  return ;
}
