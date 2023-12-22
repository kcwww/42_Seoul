/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:25:40 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 16:01:09 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
  Bureaucrat highRanking("High Ranker", 1);
  Bureaucrat lowRanking("Low Ranker", 150);
  Bureaucrat midRanking("Mid Ranker", 50);

  ShrubberyCreationForm shrubbery("home");
  RobotomyRequestForm robotomy("Bender");

  std::cout << highRanking << std::endl;
  std::cout << lowRanking << std::endl;
  std::cout << midRanking << std::endl;

  std::cout << shrubbery << std::endl;
  std::cout << robotomy << std::endl;

  try
  {
    lowRanking.signForm(shrubbery);
    highRanking.executeForm(shrubbery);
    highRanking.executeForm(robotomy);
    highRanking.signForm(shrubbery);
    highRanking.signForm(robotomy);
    midRanking.signForm(robotomy);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    lowRanking.executeForm(shrubbery);
    highRanking.executeForm(shrubbery);
    highRanking.executeForm(robotomy);
    midRanking.executeForm(robotomy);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  return (0);
}
