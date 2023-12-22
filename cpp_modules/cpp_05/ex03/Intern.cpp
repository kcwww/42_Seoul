/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:21:50 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 16:39:05 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
  std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(Intern const &ref)
{
  std::cout << "Intern Copy constructor called" << std::endl;
  *this = ref;
}

Intern::~Intern(void)
{
  std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &ref)
{
  std::cout << "Intern Assignation operator called" << std::endl;
  if (this != &ref)
  {
  }
  return (*this);
}

const char *Intern::UnknownFormException::what() const throw()
{
  return ("Unknown Form !!");
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
  AForm *form;

  std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
  int idx;

  for (idx = 0; idx <= 3; idx++)
  {
    if (idx == 3)
      throw Intern::UnknownFormException();
    else if (formName == formNames[idx])
      break;
  }

  switch (idx)
  {
    case 0:
      form = new RobotomyRequestForm(target);
      break;
    case 1:
      form = new PresidentialPardonForm(target);
      break;
    case 2:
      form = new ShrubberyCreationForm(target);
      break;
  }

  std::cout << "Intern creates " << formName << std::endl;
  return (form);
}
