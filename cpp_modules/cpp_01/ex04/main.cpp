/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcw <kcw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:23:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/06 09:20:49 by kcw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
  if (argc == 4)
  {
    Replacer replacer(argv[1], argv[2], argv[3]);
    replacer.replace();
  }
  else
    std::cout << "Error: wrong number of arguments" << std::endl;
  return (0);
}
