/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:51:26 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 16:35:01 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default")
{
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap Default constructor called" << std::endl;
  return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
  return ;
}

FragTrap::FragTrap(const FragTrap & src)
{
  std::cout << "FragTrap Copy constructor called" << std::endl;
  *this = src;
  return ;
}

FragTrap::~FragTrap(void)
{
  std::cout << "FragTrap Destructor called" << std::endl;
  return ;
}

FragTrap	&FragTrap::operator=(const FragTrap & rhs)
{
  std::cout << "FragTrap Assignation operator called" << std::endl;
  if (this != &rhs)
  {
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  return (*this);
}

void	FragTrap::attack(std::string const & target)
{
  if (this->_energyPoints == 0 || this->_hitPoints == 0)
  {
    std::cout << "FragTrap " << this->_name << " can't attack " << target << ", because he is dead!" << std::endl;
    return ;
  }
  else
  {
    std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
  }
  return ;
}

void FragTrap::highFivesGuys(void)
{
  if (this->_energyPoints == 0 || this->_hitPoints == 0)
  {
    std::cout << "FragTrap " << this->_name << " can't high fives!" << std::endl;
    return ;
  }
  std::cout << "FragTrap " << this->_name << " want high fives!" << std::endl;
  this->_energyPoints--;
  return ;
}
