/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:30:13 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/27 17:31:31 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
  Zombie	*zombie;

  zombie = newZombie("Zombie_heap");
  zombie->announce();
  delete zombie;
  randomChump("Zombie_random");
  return (0);
}
