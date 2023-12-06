/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcw <kcw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:30:13 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/06 09:02:38 by kcw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

void  check_leaks(void)
{
  system("leaks Zombie");
}

int main(void)
{
  Zombie	*zombie;

  atexit(check_leaks);
  zombie = newZombie("Zombie_heap");
  zombie->announce();
  delete zombie;
  randomChump("Zombie_random");
  return (0);
}
