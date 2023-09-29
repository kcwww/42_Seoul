/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:52:27 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 16:34:44 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(), _name("default_diamond_name")
{
  ClapTrap::_name = "default_clap_name";
  this->_energyPoints = ScavTrap::_energyPoints;
  std::cout << "DiamondTrap Default constructor called" << std::endl;
  return ;
}

DiamondTrap::~DiamondTrap(void)
{
  std::cout << "DiamondTrap Destructor called" << std::endl;
  return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
  ClapTrap::_name = name + "_clap_name";
  this->_energyPoints = ScavTrap::_energyPoints;
  std::cout << "DiamondTrap "<< this->_name <<" constructor called" << std::endl;
  return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src)
{
  std::cout << "DiamondTrap Copy constructor called" << std::endl;
  *this = src;
  return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap & rhs)
{
  std::cout << "DiamondTrap Assignation operator called" << std::endl;
  if (this != &rhs)
  {
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  return (*this);
}

void	DiamondTrap::attack(std::string const & target)
{
  ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
  if (this->_hitPoints == 0 || this->_energyPoints == 0)
  {
    std::cout << "DiamondTrap is dead" << std::endl;
    return ;
  }
  std::cout << "DiamondTrap name is " << this->_name << std::endl;
  std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
  this->_energyPoints--;
}
