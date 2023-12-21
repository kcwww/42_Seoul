/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:54:22 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/21 17:09:51 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP


#include <iostream>

class Bureaucrat;

class Form
{
  private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

    Form();
  public:
    Form(const std::string & name, int signGrade, int execGrade);
    Form(Form const & ref);
    ~Form();
    Form &operator=(Form const & ref);

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

    const std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(Bureaucrat & bureaucrat);
};

std::ostream &operator<<(std::ostream &os, Form const &ref);

#endif
