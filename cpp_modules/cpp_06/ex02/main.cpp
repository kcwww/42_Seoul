/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:28:50 by chanwoki          #+#    #+#             */
/*   Updated: 2024/01/23 20:54:34 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void checkleaks(void)
{
    system("leaks DynamicCast | grep 'leaks for' | cut -d' ' -f3");
}

int main()
{
  atexit(checkleaks);
    Base *base = generate();
    Base *base2 = generate();
    Base *base3 = generate();
    Base *base4 = generate();
    Base *base5 = generate();
    identify(base);
    identify(*base);
    identify(base2);
    identify(*base2);
    identify(base3);
    identify(*base3);
    identify(base4);
    identify(*base4);
    identify(base5);
    identify(*base5);
    delete base;
    delete base2;
    delete base3;
    delete base4;
    delete base5;
    return (0);
}
