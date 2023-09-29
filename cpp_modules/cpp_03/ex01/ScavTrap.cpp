/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:51:26 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 15:43:35 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default")
{
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  this->_mode = "normal";
  std::cout << "ScavTrap Default constructor called" << std::endl;
  return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
  return ;
}

ScavTrap::ScavTrap(const ScavTrap & src)
{
  std::cout << "ScavTrap Copy constructor called" << std::endl;
  *this = src;
  return ;
}

ScavTrap::~ScavTrap(void)
{
  std::cout << "ScavTrap Destructor called" << std::endl;
  return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap & rhs)
{
  std::cout << "ScavTrap Assignation operator called" << std::endl;
  if (this != &rhs)
  {
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  return (*this);
}

void	ScavTrap::attack(std::string const & target)
{
  if (this->_energyPoints == 0 || this->_hitPoints == 0)
  {
    std::cout << "ScavTrap " << this->_name << " can't attack " << target << ", because he is dead!" << std::endl;
    return ;
  }
  else
  {
    std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
  }
  return ;
}

void	ScavTrap::guardGate(void)
{
  if (this->_energyPoints == 0 || this->_hitPoints == 0)
  {
    std::cout << "ScavTrap " << this->_name << " can't enter in Gate keeper mode, because he is dead!" << std::endl;
    return ;
  }
  std::cout << "ScavTrap " << this->_name << " has enterred in Gate keeper mode" << std::endl;
  this->_mode = "Gate keeper";
  this->_energyPoints--;
  return ;
}
