/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:09:45 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/22 16:10:35 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
    std::string _target;
    PresidentialPardonForm(void);

  public:
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &ref);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &);

    std::string const &getTarget(void) const;
    void execute(Bureaucrat const &) const;
};

#endif
