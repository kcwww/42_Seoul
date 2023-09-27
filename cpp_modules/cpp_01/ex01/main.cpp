/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:49:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/27 17:51:59 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void  check_leaks(void)
{
  system("leaks ZombieHorde");
}

int main (void)
{
  Zombie	*zombie;
  int		i;

  atexit(check_leaks);
  i = 0;
  zombie = zombieHorde(10, "zombie");
  while (i < 10)
  {
    zombie[i].announce();
    i++;
  }
  delete [] zombie;
  return (0);
}
