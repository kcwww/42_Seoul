/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:12:59 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:47:25 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
  for (int i = 0; i < 4; i++)
    this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
  for (int i = 0; i < 4; i++)
    this->_materia[i] = src._materia[i] ? src._materia[i]->clone() : NULL;
}

MateriaSource::~MateriaSource()
{
  for (int i = 0; i < 4; i++)
    delete this->_materia[i];
}

MateriaSource & MateriaSource::operator=(const MateriaSource &src)
{
  if (this != &src)
  {
    for (int i = 0; i < 4; i++)
    {
      delete this->_materia[i];
      this->_materia[i] = src._materia[i] ? src._materia[i]->clone() : NULL;
    }
  }
  return (*this);
}


void MateriaSource::learnMateria(Amateria *m)
{
  if (m == NULL)
    return ;
  for (int i = 0; i < 4; i++)
  {
    if (this->_materia[i] == NULL)
    {
      this->_materia[i] = m;
      break;
    }
  }
}

Amateria *MateriaSource::createMateria(std::string const & type)
{
  for (int i = 0; i < 4; i++)
  {
    if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
      return (this->_materia[i]->clone());
  }
  return (NULL);
}
