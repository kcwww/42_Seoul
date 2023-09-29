/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:14:22 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 12:47:05 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
  private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
  public:
    Fixed(void);
    Fixed(Fixed const & src);
    ~Fixed(void);
    Fixed & operator=(Fixed const & rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed(int const n);
    Fixed(float const n);

    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(Fixed const & rhs) const;
    bool operator<(Fixed const & rhs) const;
    bool operator>=(Fixed const & rhs) const;
    bool operator<=(Fixed const & rhs) const;
    bool operator==(Fixed const & rhs) const;
    bool operator!=(Fixed const & rhs) const;

    Fixed operator+(Fixed const & rhs) const;
    Fixed operator-(Fixed const & rhs) const;
    Fixed operator*(Fixed const & rhs) const;
    Fixed operator/(Fixed const & rhs) const;

    Fixed & operator++(void);
    Fixed & operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed & min(Fixed & a, Fixed & b);
    static Fixed & max(Fixed & a, Fixed & b);
    static Fixed const & min(Fixed const & a, Fixed const & b);
    static Fixed const & max(Fixed const & a, Fixed const & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
