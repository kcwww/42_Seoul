/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:26 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/28 20:31:13 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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
