/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:57:09 by chanwoki          #+#    #+#             */
/*   Updated: 2024/01/22 17:01:10 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <sstream>

class ScalarConverter {
  public:
    static void convert(const std::string &literal);
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter & ref);
    ScalarConverter &operator =(const ScalarConverter & ref);
    ~ScalarConverter();

    static char toChar(double value);
    static int toInt(double value);
    static float toFloat(double value);
    static double toDouble(const std::string &literal);
};

#endif
