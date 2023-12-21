/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:25:40 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/21 18:21:34 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
  Bureaucrat highRanking("High Ranker", 1);
  Bureaucrat lowRanking("Low Ranker", 150);

  ShrubberyCreationForm shrubbery("home");

  std::cout << highRanking << std::endl;
  std::cout << lowRanking << std::endl;

  std::cout << shrubbery << std::endl;

  try
  {
    lowRanking.signForm(shrubbery);
    highRanking.executeForm(shrubbery);
    highRanking.signForm(shrubbery);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    lowRanking.executeForm(shrubbery);
    highRanking.executeForm(shrubbery);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  return (0);
}
