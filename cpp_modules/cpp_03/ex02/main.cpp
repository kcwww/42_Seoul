/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:17:14 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 15:18:50 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
  FragTrap a("a");
  FragTrap b("b");

  a.attack("b");
  b.takeDamage(100);
  b.beRepaired(5);
  a.highFivesGuys();
  b.highFivesGuys();
  return (0);
}
