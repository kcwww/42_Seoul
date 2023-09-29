/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:17:14 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 15:12:35 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
  ScavTrap a("a");
  ScavTrap b("b");

  a.attack("b");
  b.takeDamage(100);
  b.beRepaired(5);
  b.guardGate();
  a.guardGate();
  return (0);
}
