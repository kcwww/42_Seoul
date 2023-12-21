/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:25:40 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/21 18:15:49 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
  try
  {
    Bureaucrat b1("B1", 1);
    Bureaucrat b2("B2", 150);
    Form f1("F1", 1, 1);
    Form f2("F2", 150, 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    b1.signForm(f1);
    b2.signForm(f2);
    b1.signForm(f2);
    b2.signForm(f1);
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
