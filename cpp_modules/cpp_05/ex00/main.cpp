/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:25:40 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/20 17:19:01 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
  try {
    Bureaucrat b("Bureaucrat", 1);
    std::cout << b << std::endl;
    Bureaucrat c("Bureaucrat", 0);
    std::cout << c << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
