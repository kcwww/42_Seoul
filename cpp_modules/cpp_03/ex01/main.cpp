/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:17:14 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 15:10:23 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
  ScavTrap a("a");
  ScavTrap b("b");

  a.attack("b");
  b.takeDamage(5);
  b.beRepaired(5);
  b.guardGate();
  return (0);
}
