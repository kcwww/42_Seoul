/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:54:22 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/21 18:06:59 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:
  const std::string _name;
  bool _isSigned;
  const int _signGrade;
  const int _execGrade;

  AForm();

public:
  AForm(const std::string &name, int signGrade, int execGrade);
  AForm(AForm const &ref);
  ~AForm();
  AForm &operator=(AForm const &ref);

  class GradeTooHighException : public std::exception
  {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception
  {
  public:
    const char *what() const throw();
  };

  class NotSignedException : public std::exception
  {
  public:
    const char *what() const throw();
  };

  void verifyExec(Bureaucrat const &executor) const;

  const std::string getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(Bureaucrat &bureaucrat);

  virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm const &ref);

#endif
