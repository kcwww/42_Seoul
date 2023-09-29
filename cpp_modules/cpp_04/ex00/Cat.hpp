/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:26 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:15:10 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

class Cat
{
  private:

  public:
    Cat();
    Cat(const Cat& ref);
    ~Cat();

    Cat&	operator=(const Cat& ref);
};

#endif
