/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:49:09 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 15:46:50 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
  std::string _target;
  ShrubberyCreationForm(void);

public:
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &ref);
  ~ShrubberyCreationForm(void);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);

  std::string const &getTarget(void) const;
  void execute(Bureaucrat const &) const;
};

#endif
