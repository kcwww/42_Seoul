/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:10:43 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 16:11:44 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
  std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
  return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
  std::cout << "PresidentialPardonForm constructor called" << std::endl;
  return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref) : AForm(ref)
{
  std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
  *this = ref;
  return;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "PresidentialPardonForm Destructor called" << std::endl;
  return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
  std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
  if (this != &ref)
  {
    this->_target = ref.getTarget();
  }
  return (*this);
}

std::string const &PresidentialPardonForm::getTarget() const
{
  return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
  verifyExec(executor);

  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
  return;
}
