/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:25:40 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 16:38:31 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
  Bureaucrat highRanking("High Ranker", 1);
  Bureaucrat lowRanking("Low Ranker", 150);
  Bureaucrat midRanking("Mid Ranker", 50);

  Intern intern;

  AForm *shrubbery = intern.makeForm("shrubbery creation", "home");
  AForm *robotomy = intern.makeForm("robotomy request", "Bender");
  AForm *presidential = intern.makeForm("presidential pardon", "Zaphod");



  std::cout << highRanking << std::endl;
  std::cout << lowRanking << std::endl;
  std::cout << midRanking << std::endl;

  std::cout << *shrubbery << std::endl;
  std::cout << *robotomy << std::endl;
  std::cout << *presidential << std::endl;

  try
  {
    lowRanking.signForm(*shrubbery);
    highRanking.executeForm(*shrubbery);
    highRanking.executeForm(*robotomy);
    highRanking.signForm(*shrubbery);
    highRanking.signForm(*robotomy);
    midRanking.signForm(*robotomy);
    lowRanking.signForm(*presidential);
    highRanking.signForm(*presidential);
    std::cout << "\n\n" << std::endl;
    AForm *test = intern.makeForm("test", "test");
    std::cout << '\n' << *test << '\n' << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    lowRanking.executeForm(*shrubbery);
    highRanking.executeForm(*shrubbery);
    highRanking.executeForm(*robotomy);
    midRanking.executeForm(*robotomy);
    lowRanking.executeForm(*presidential);
    highRanking.executeForm(*presidential);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }


  delete shrubbery;
  delete robotomy;
  delete presidential;

  return (0);
}
