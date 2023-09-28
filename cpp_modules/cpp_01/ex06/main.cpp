/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:39:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 16:40:18 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
    return (0);
  }
  Harl harl;
  harl.complain(argv[1]);
  return (0);
}
