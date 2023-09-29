/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:00:49 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 13:12:41 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
  Point a(0, 0);
  Point b(10, 0);
  Point c(0, 10);

  Point point1(3, 3);

  std::cout << bsp(a, b, c, point1) << std::endl;

  Point point2(5, 55);

  std::cout << bsp(a, b, c, point2) << std::endl;
}
