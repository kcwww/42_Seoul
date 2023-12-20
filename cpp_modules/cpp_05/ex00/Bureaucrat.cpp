/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:25:35 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/20 17:19:31 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
  std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
  std::cout << "Bureaucrat Default constructor called" << std::endl;
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name)
{
  std::cout << "Bureaucrat Copy constructor called" << std::endl;
  *this = ref;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
  std::cout << "Bureaucrat Assignation operator called" << std::endl;
  if (this != &ref) {
    this->_grade = ref._grade;
  }
  return (*this);
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat Destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade too high!!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade too low!!");
}

const std::string& Bureaucrat::getName() const
{
  return (this->_name);
}

int Bureaucrat::getGrade() const
{
  return (this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref)
{
  os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
  return (os);
}
