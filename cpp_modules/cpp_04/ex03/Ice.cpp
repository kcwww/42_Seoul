/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:12:37 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:50:52 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : Amateria("ice")
{
}

Ice::Ice(const Ice &src) : Amateria(src)
{
}

Ice::~Ice(void)
{
}

Ice &Ice::operator=(const Ice &src)
{
  if (this != &src)
  {
    Amateria::operator=(src);
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
