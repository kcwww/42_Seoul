/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:28:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 18:30:53 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
  private:
    int _value;
    static const int _bits = 8;

  public:
    Fixed();
    Fixed(const Fixed& ref);
    ~Fixed();
    Fixed& operator=(const Fixed& ref);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
