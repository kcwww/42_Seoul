/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:12:16 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:49:57 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : Amateria("cure")
{
}

Cure::Cure(const Cure &src) : Amateria(src)
{
}

Cure::~Cure(void)
{
}

Cure &Cure::operator=(const Cure &src)
{
  if (this != &src)
  {
    Amateria::operator=(src);
  }
  return (*this);
}

Amateria *Cure::clone(void) const
{
  return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
