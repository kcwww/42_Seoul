/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:12:37 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:55:57 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice &src) : AMateria(src)
{
}

Ice::~Ice(void)
{
}

Ice &Ice::operator=(const Ice &src)
{
  if (this != &src)
  {
    AMateria::operator=(src);
  }
  return (*this);
}

Amateria *Ice::clone(void) const
{
  return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
