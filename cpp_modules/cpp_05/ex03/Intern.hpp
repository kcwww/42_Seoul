/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:19:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 16:23:49 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
  public:
    Intern(void);
    Intern(Intern const &ref);
    ~Intern(void);
    Intern &operator=(Intern const &);

    AForm *makeForm(std::string const &formName, std::string const &target);

    class UnknownFormException : public std::exception
    {
      public:
        const char *what() const throw();
    };
};

#endif
