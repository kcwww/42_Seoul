/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:54:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/21 18:06:53 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
  std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const std::string & name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
  if (signGrade < 1 || execGrade < 1)
    throw AForm::GradeTooHighException();
  else if (signGrade > 150 || execGrade > 150)
    throw AForm::GradeTooLowException();
  else
    std::cout << "AForm Constructor called" << std::endl;
}

AForm::~AForm()
{
  std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(AForm const & ref) : _name(ref._name), _signGrade(ref._signGrade), _execGrade(ref._execGrade)
{
  std::cout << "AForm Copy Constructor called" << std::endl;
  *this = ref;
}

AForm &AForm::operator=(AForm const & ref)
{
  std::cout << "AForm Assignation operator called" << std::endl;
  if (this != &ref)
    this->_isSigned = ref._isSigned;
  return (*this);
}

const std::string AForm::getName() const
{
  return (this->_name);
}

bool AForm::getIsSigned() const
{
  return (this->_isSigned);
}

int AForm::getSignGrade() const
{
  return (this->_signGrade);
}

int AForm::getExecGrade() const
{
  return (this->_execGrade);
}

void AForm::beSigned(Bureaucrat & bureaucrat)
{
  if (bureaucrat.getGrade() > this->_signGrade)
    throw AForm::GradeTooLowException();
  else
    this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return ("Grade is too high!!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
  return ("Grade is too low!!");
}

std::ostream &operator<<(std::ostream &os, AForm const &ref)
{
  os << ref.getName() << " AForm is ";
  if (ref.getIsSigned())
    os << "signed";
  else
    os << "not signed";
  os << " and require grade " << ref.getSignGrade() << " to be signed and grade " << ref.getExecGrade() << " to be executed." << std::endl;
  return (os);
}

const char *AForm::NotSignedException::what() const throw()
{
  return ("Form is not signed!!");
}

void AForm::verifyExec(Bureaucrat const & executor) const
{
  if (this->getIsSigned() == false)
  {
    throw AForm::NotSignedException();
  }
  else if (executor.getGrade() > this->getExecGrade())
  {
    throw AForm::GradeTooLowException();
  }
}
