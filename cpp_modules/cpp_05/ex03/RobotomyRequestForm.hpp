/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:35:00 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 15:46:01 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  private:
    std::string _target;
    RobotomyRequestForm();

  public:
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &ref);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);
    ~RobotomyRequestForm();

    std::string const &getTarget() const;
    void execute(Bureaucrat const &executor) const;
};

#endif
