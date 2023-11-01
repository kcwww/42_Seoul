/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:11:50 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:39:07 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
};

Character::Character(Character const & src) : _name(src._name)
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = src._materia[i] ? src._materia[i]->clone() : NULL;
};

Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
        delete this->_materia[i];
};

Character & Character::operator=(Character const & src)
{
  if (this != &src) {
    this->_name = src._name;
    for (int i = 0; i < 4; i++)
    {
        delete this->_materia[i];
        this->_materia[i] = src._materia[i] ? src._materia[i]->clone() : NULL;
    }
  }
    return (*this);
};

std::string const & Character::getName(void) const
{
    return (this->_name);
};


void Character::equip(Amateria *m)
{
  for (int i = 0; i < 4; i++)
  {
      if (this->_materia[i] == NULL)
      {
          this->_materia[i] = m;
          break;
      }
  }
};

void Character::unequip(int idx)
{
  if (idx >= 0 && idx < 4)
      this->_materia[idx] = NULL;
};

void Character::use(int idx, ICharacter & target)
{
  if (idx >= 0 && idx < 4 && this->_materia[idx] != NULL)
      this->_materia[idx]->use(target);
};
