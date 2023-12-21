/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:25:38 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/21 18:14:44 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

class Form;

class Bureaucrat
{
  private:
    std::string const _name;
    int _grade;
  public:
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

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& ref);
    Bureaucrat& operator=(const Bureaucrat& ref);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref);

#endif
