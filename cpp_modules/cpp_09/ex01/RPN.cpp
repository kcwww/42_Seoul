/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:53:22 by dkham             #+#    #+#             */
/*   Updated: 2024/06/03 01:41:10 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>

RPN::RPN() {}


RPN::RPN(const std::string& expression) {
    try {
        int result = evaluate(expression);
        std::cout << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}


RPN::RPN(const RPN& other) {
    *this = other;
}


RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        // Copy the data members from the other object
    }
    return *this;
}


RPN::~RPN() {}


bool RPN::isOperator(const std::string& token) {
    
    return token == "+" || token == "-" || token == "*" || token == "/";
}


bool RPN::isNumber(const std::string& token) {
    bool hasDecimal = false;
    
    for (std::string::size_type i = 0; i < token.size(); ++i) {
        char c = token[i];
        if (c == '.') {
            
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!std::isdigit(c) && !(c == '-' && i == 0)) {
            
            return false;
        }
    }
    
    return !hasDecimal;
}


int RPN::performOperation(int a, int b, const std::string& op) {
    
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    
    if (op == "/") return b == 0 ? throw std::runtime_error("Division by zero") : a / b;
    
    throw std::runtime_error("Invalid operator");
}


int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<int> values;


    while (iss >> token) {

        if (isOperator(token)) {

            if (values.size() < 2) {
                throw std::runtime_error("Invalid expression: insufficient operands");
            }

            int b = values.top(); values.pop();
            int a = values.top(); values.pop();

            values.push(performOperation(a, b, token));
        } else {

            if (!isNumber(token)) {

                throw std::runtime_error("Invalid expression: invalid input '" + token + "'");
            }


            std::istringstream converter(token);
            int number;
            converter >> number;


            if (number >= 10) {
                throw std::runtime_error("Invalid expression: number should be less than 10");
            }


            values.push(number);
        }
    }


    if (values.size() != 1) throw std::runtime_error("Invalid expression");

    return values.top();
}
