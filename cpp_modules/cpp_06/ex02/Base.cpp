/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:28:42 by chanwoki          #+#    #+#             */
/*   Updated: 2024/01/23 20:52:34 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Inheritance.hpp"

Base::~Base()
{
    return ;
}

Base *generate(void)
{
    int i;

    i = rand() % 3;
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "Ref A" << std::endl;
        (void)a;
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            std::cout << "Ref B" << std::endl;
            (void)b;
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                std::cout << "Ref C" << std::endl;
                (void)c;
            }
            catch (std::exception &e)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}
