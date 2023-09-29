/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:17:14 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 15:52:21 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
  DiamondTrap a("a");
  DiamondTrap b("b");

  a.attack("b");
  b.takeDamage(100);
  b.beRepaired(5);
  a.highFivesGuys();
  b.highFivesGuys();
  a.guardGate();
  b.guardGate();
  return (0);
}
