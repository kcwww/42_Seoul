/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:55:26 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/21 18:18:12 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
  std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
  std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : AForm(src), _target(src.getTarget())
{
  std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
  std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
  if (this != &rhs)
  {
    this->_target = rhs.getTarget();
  }
  return (*this);
}

std::string const &ShrubberyCreationForm::getTarget(void) const
{
  return (this->_target);
}

void ShrubberyCreationForm::execute (Bureaucrat const & ref) const
{
  verifyExec(ref);

  std::string filename = this->_target + "_shrubbery";
  std::ofstream ofs(filename.c_str());
  if (ofs) {
    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;
    ofs << "     //   \\\\" << std::endl;
    ofs << "    //     \\\\" << std::endl;
    ofs << "   //       \\\\" << std::endl;
    ofs << "  //         \\\\" << std::endl;
    ofs << " =================" << std::endl;
    ofs.close();
  } else {
    throw std::runtime_error("Error: Unable to write to file");
  }
}
