/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:54:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/21 17:12:54 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
  std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string & name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
  if (signGrade < 1 || execGrade < 1)
    throw Form::GradeTooHighException();
  else if (signGrade > 150 || execGrade > 150)
    throw Form::GradeTooLowException();
  else
    std::cout << "Form Constructor called" << std::endl;
}

Form::~Form()
{
  std::cout << "Form Destructor called" << std::endl;
}

Form::Form(Form const & ref) : _name(ref._name), _signGrade(ref._signGrade), _execGrade(ref._execGrade)
{
  std::cout << "Form Copy Constructor called" << std::endl;
  *this = ref;
}

Form &Form::operator=(Form const & ref)
{
  std::cout << "Form Assignation operator called" << std::endl;
  if (this != &ref)
    this->_isSigned = ref._isSigned;
  return (*this);
}

const std::string Form::getName() const
{
  return (this->_name);
}

bool Form::getIsSigned() const
{
  return (this->_isSigned);
}

int Form::getSignGrade() const
{
  return (this->_signGrade);
}

int Form::getExecGrade() const
{
  return (this->_execGrade);
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
  if (bureaucrat.getGrade() > this->_signGrade)
    throw Form::GradeTooLowException();
  else
    this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
  return ("Grade is too high!!");
}

const char *Form::GradeTooLowException::what() const throw()
{
  return ("Grade is too low!!");
}

std::ostream &operator<<(std::ostream &os, Form const &ref)
{
  os << ref.getName() << " Form is ";
  if (ref.getIsSigned())
    os << "signed";
  else
    os << "not signed";
  os << " and require grade " << ref.getSignGrade() << " to be signed and grade " << ref.getExecGrade() << " to be executed." << std::endl;
  return (os);
}
