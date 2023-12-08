/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:38:15 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/08 13:16:47 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed const b( 10 );
  Fixed const c( 42.4112f );
  Fixed const d( b );
  a = Fixed( 1234.4321211f );
  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;
  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;
  std::cout << "a is " << a.toFloat() << " as float" << std::endl;
  std::cout << "b is " << b.toFloat() << " as float" << std::endl;
  std::cout << "c is " << c.toFloat() << " as float" << std::endl;
  std::cout << "d is " << d.toFloat() << " as float" << std::endl;
  return 0;
}
