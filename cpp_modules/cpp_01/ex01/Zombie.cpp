/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:27:12 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/27 17:37:52 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
  return ;
}

Zombie::Zombie(std::string name)
{
  std::cout << "A new zombie is born" << std::endl;
  this->_name = name;
}

void Zombie::announce(void)
{
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
  this->_name = name;
}

Zombie::~Zombie(void)
{
  std::cout << this->_name << " is dead" << std::endl;
}
