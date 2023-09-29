/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:38:42 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 11:53:23 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
    int					_value;
    static const int	_bits = 8;

  public:
    Fixed(void);
    Fixed(Fixed const &src);
    Fixed(int const value);
    Fixed(float const value);
    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    int		getRawBits(void) const;
    void	setRawBits(int const raw);
    float	toFloat(void) const;
    int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
