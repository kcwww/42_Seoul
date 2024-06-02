/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:48:58 by dkham             #+#    #+#             */
/*   Updated: 2024/06/03 01:39:24 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>

class RPN {
public:
    RPN();
    RPN(const std::string& expression);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    int evaluate(const std::string& expression);

private:
    bool isOperator(const std::string& token);
    bool isNumber(const std::string& token);
    int performOperation(int a, int b, const std::string& op);
};

#endif
