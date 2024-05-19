/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:19:35 by chanwookim        #+#    #+#             */
/*   Updated: 2024/05/20 00:20:39 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <limits>
#include <cmath>
#include <iostream>

class Span {
public:
    
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        std::cout << "addNumber template used" << std::endl;
        while (begin != end) {
            addNumber(*begin);
            ++begin;
        }
    }

    int shortestSpan() const;
    long long longestSpan() const;
    
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
};

#endif
