/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:46:36 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 12:57:59 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
  public:
    Point(void);
    Point(Point const & src);
    ~Point(void);

    Point & operator=(Point const & rhs);

    Fixed const getX(void) const;
    Fixed const getY(void) const;

    Point(Fixed const x, Fixed const y);

  private:
    Fixed const _x;
    Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
