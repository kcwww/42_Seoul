/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:29 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:15:19 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

class Dog
{
  private:

  public:
    Dog();
    Dog(const Dog& ref);
    ~Dog();

    Dog&	operator=(const Dog& ref);
};

#endif
