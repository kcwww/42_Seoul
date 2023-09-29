/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:17:14 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 14:43:03 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
  ClapTrap clapTrap("CT");
  clapTrap.attack("target");
  clapTrap.takeDamage(5);
  clapTrap.beRepaired(5);
  return (0);
}
