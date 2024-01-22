/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:25:40 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/26 14:31:16 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Invaild number of argument. Check it!" << std::endl;
    return (1);
  }
  ScalarConverter::convert(av[1]);
  return (0);
}
