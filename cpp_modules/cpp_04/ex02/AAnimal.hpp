/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:18 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/28 20:37:45 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
  protected:
    std::string _type;

  public:
    AAnimal();
    AAnimal(const AAnimal& ref);
    virtual ~AAnimal();
    AAnimal&	operator=(const AAnimal& ref);
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif
