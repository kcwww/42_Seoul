/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:21:38 by chanwookim        #+#    #+#             */
/*   Updated: 2024/05/20 00:22:46 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::length_error("Span is already full");
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

long long Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }

    int minElem = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElem = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<long long>(maxElem) - static_cast<long long>(minElem);
}
