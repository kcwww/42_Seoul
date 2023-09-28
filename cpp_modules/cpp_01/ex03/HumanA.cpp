/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:03:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 12:53:12 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
  std::cout << "HumanA constructor called" << std::endl;
  return ;
}

HumanA::~HumanA(void)
{
  std::cout << "HumanA destructor called" << std::endl;
  return ;
}

void	HumanA::attack(void)
{
  std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
  return ;
}
