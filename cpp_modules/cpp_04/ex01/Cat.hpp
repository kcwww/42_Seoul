/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:26 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:58:34 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
    Brain *_brain;
  public:
    Cat();
    Cat(const Cat& ref);
    ~Cat();
    Cat&	operator=(const Cat& ref);
    void makeSound() const;
    Brain *getBrain() const;
};

#endif
