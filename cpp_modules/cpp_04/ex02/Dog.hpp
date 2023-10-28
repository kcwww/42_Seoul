/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:29 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/28 20:31:16 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
  private:
    Brain *_brain;
  public:
    Dog();
    Dog(const Dog& ref);
    ~Dog();
    Dog&	operator=(const Dog& ref);
    void makeSound() const;
    Brain *getBrain() const;
};

#endif
