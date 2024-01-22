/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:06:01 by chanwoki          #+#    #+#             */
/*   Updated: 2024/01/22 17:21:42 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
    return ;
}

Serializer::Serializer(Serializer const & src)
{
    *this = src;
    return ;
}

Serializer::~Serializer(void)
{
    return ;
}

Serializer & Serializer::operator=(Serializer const & rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw;

    raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr;

    ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}
