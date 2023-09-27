/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:34:52 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/27 17:49:06 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>


Zombie	*zombieHorde(int N, std::string name)
{
  Zombie	*zombie;
  std::stringstream number;
  int		i;

  i = 0;
  zombie = new Zombie[N];
  while (i < N)
  {
    number << i;
    zombie[i].setName(name + number.str());
    i++;
  }
  return (zombie);
}
