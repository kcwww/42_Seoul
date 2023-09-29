/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:10:36 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 17:15:42 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

class WrongCat
{
  private:

  public:
    WrongCat();
    WrongCat(const WrongCat& ref);
    ~WrongCat();

    WrongCat&	operator=(const WrongCat& ref);
};

#endif
