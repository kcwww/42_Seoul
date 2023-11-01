/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:11:42 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:15:57 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amateria.hpp"
#include "ICharacter.hpp"

Amateria::Amateria(void) : _type("default")
{
};

Amateria::Amateria(std::string const & type) : _type(type)
{
};

Amateria::Amateria(Amateria const & src) : _type(src._type)
{
    *this = src;
};

Amateria::~Amateria(void)
{
};

Amateria & Amateria::operator=(Amateria const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return (*this);
};

std::string const & Amateria::getType(void) const
{
    return (this->_type);
};

void Amateria::use(ICharacter & target)
{
    (void)target;
};

