/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:18 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:30:48 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
  protected:
    std::string _type;

  public:
    Animal();
    Animal(const Animal& ref);
    virtual ~Animal();
    Animal&	operator=(const Animal& ref);
    virtual void makeSound() const;
    std::string getType() const;
};

#endif
