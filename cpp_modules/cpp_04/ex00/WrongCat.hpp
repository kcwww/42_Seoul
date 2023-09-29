/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:36 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:38:49 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
    WrongCat();
    WrongCat(const WrongCat& ref);
    ~WrongCat();
    WrongCat&	operator=(const WrongCat& ref);
    void makeSound() const;
};

#endif
