/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:17:12 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 15:11:09 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
  std::cout << "ClapTrap Default constructor called" << std::endl;
  return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
  std::cout << "ClapTrap "<< this->_name <<" constructor called" << std::endl;
  return ;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
  std::cout << "ClapTrap Copy constructor called" << std::endl;
  *this = src;
  return ;
}

ClapTrap::~ClapTrap(void)
{
  std::cout << "ClapTrap Destructor called" << std::endl;
  return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap & rhs)
{
  std::cout << "ClapTrap Assignation operator called" << std::endl;
  if (this != &rhs)
  {
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  return (*this);
}

void	ClapTrap::attack(std::string const & target)
{
  if (this->_energyPoints == 0 || this->_hitPoints == 0)
  {
    std::cout << "ClapTrap " << this->_name << " can't attack " << target << ", because he is dead!" << std::endl;
    return ;
  }
  else
  {
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
  }
  return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
  if (amount >= this->_hitPoints)
    this->_hitPoints = 0;
  else
    this->_hitPoints -= amount;


  std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
  if (this->_hitPoints == 0)
    std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
  return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
  if (this->_hitPoints == 0 || this->_energyPoints == 0)
  {
    std::cout << "ClapTrap " << this->_name << " can't be repaired, because he is dead!" << std::endl;
    return ;
  }
  else
  {
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " be repaired " << amount << " points of damage!" << std::endl;
  }
  return ;
}
