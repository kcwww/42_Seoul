/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:11:42 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/04 16:40:18 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : _type("default")
{
};

AMateria::AMateria(std::string const & type) : _type(type)
{
};

AMateria::AMateria(AMateria const & src) : _type(src._type)
{
    *this = src;
};

AMateria::~AMateria(void)
{
};

AMateria & AMateria::operator=(AMateria const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return (*this);
};

std::string const & AMateria::getType(void) const
{
    return (this->_type);
};

void AMateria::use(ICharacter & target)
{
    (void)target;
};

