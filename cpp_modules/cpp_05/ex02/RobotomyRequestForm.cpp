/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:46:09 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 15:50:57 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
  std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
  return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
  return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) : AForm(ref)
{
  std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
  *this = ref;
  return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << "RobotomyRequestForm Destructor called" << std::endl;
  return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
  std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
  if (this != &ref)
  {
    this->_target = ref.getTarget();
  }
  return (*this);
}

std::string const &RobotomyRequestForm::getTarget() const
{
  return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
  verifyExec(executor);

  std::cout << "* drilling noises *" << std::endl;
  if (rand() % 2) {
    std::cout << this->_target << " has been robotomized successfully" << std::endl;
  } else {
    std::cout << this->_target << " robotomization failed" << std::endl;
  }
  return;
}
