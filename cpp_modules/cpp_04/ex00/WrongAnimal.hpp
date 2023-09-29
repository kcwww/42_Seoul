/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:15:35 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

class WrongAnimal
{
  private:

  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& ref);
    ~WrongAnimal();

    WrongAnimal&	operator=(const WrongAnimal& ref);
};

#endif
