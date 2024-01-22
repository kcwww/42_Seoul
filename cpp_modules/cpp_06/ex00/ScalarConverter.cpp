/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:54:48 by chanwoki          #+#    #+#             */
/*   Updated: 2024/01/22 17:03:54 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
  std::cout << "Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter & ref)
{
  std::cout << "Copy Constructor called" << std::endl;
  *this = ref;
}

ScalarConverter::~ScalarConverter()
{
  std::cout << "Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator =(const ScalarConverter & ref)
{
  std::cout << "Assignation operator called" << std::endl;
  (void)ref;
  return (*this);
}

char ScalarConverter::toChar(double value)
{
  if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
    throw std::runtime_error("impossible");
  char c = static_cast<char>(value);
  if (!std::isprint(c))
    throw std::runtime_error("Non displayable");
  return c;
}

int ScalarConverter::toInt(double value)
{
  if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    throw std::runtime_error("impossible");
  return static_cast<int>(value);
}

float ScalarConverter::toFloat(double value)
{
  if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
    throw std::runtime_error("impossible");
  return static_cast<float>(value);
}

double ScalarConverter::toDouble(const std::string &literal)
{
  std::string cleanedString = literal;

  if (!cleanedString.empty() && (cleanedString[cleanedString.size() - 1] == 'f')) {
  cleanedString = cleanedString.substr(0, cleanedString.size() - 1);
  }
  std::istringstream iss(cleanedString);
  double result;
  iss >> result;
  if (iss.fail() || !iss.eof()) {
    throw std::runtime_error("Failed to convert string to double");
  }
  return result;
}

void ScalarConverter::convert(const std::string &lit)
{
  if (lit == "inf" || lit == "+inf" || lit == "-inf" || lit == "inff" || lit == "+inff" || lit == "-inff" || lit == "nan" || lit == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (lit == "inf" || lit == "+inf" || lit == "inff" || lit == "+inff") {
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        } else if (lit == "-inf" || lit == "-inff" || lit == "-inf" || lit == "-inff") {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        } else if (lit == "nan" || lit == "nanf") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        return;

    } else if (lit.length() == 1 && !std::isdigit(lit[0])) {
        char cValue = static_cast<char>(lit[0]);
        if (std::isprint(cValue) && !std::isdigit(cValue)) {
            std::cout << "char: '" << cValue << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: impossible" << std::endl;
        std::cout << "float impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    else {
        try {
            double doubleValue = toDouble(lit);

            try {
                char cValue = toChar(doubleValue);
                std::cout << "char: '" << cValue << "'" << std::endl;
            } catch (const std::exception &e) {
                std::cout << "char: " << e.what() << std::endl;
            }

            try {
                int iValue = toInt(doubleValue);
                std::cout << "int: " << iValue << std::endl;
            } catch (const std::exception &e) {
                std::cout << "int: " << e.what() << std::endl;
            }

            try {
                float fValue = toFloat(doubleValue);
                std::cout << "float: " << fValue;
                if (fValue == floor(fValue)) {
                    std::cout << ".0";
                }
                std::cout << "f" << std::endl;
            } catch (const std::exception &e) {
                std::cout << "float: " << e.what() << std::endl;
            }


            std::cout << "double: " << doubleValue;
            if (doubleValue == static_cast<int>(doubleValue)) {
                std::cout << ".0";
            }
            std::cout << std::endl;

        } catch (const std::exception &e) {
            std::cout << "char: " << "impossible" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            std::cout << "float: " << "impossible" << std::endl;
            std::cout << "double: " << "impossible" << std::endl;
        }
    }
}
