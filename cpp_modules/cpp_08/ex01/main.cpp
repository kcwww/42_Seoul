/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:30:43 by chanwookim        #+#    #+#             */
/*   Updated: 2024/05/20 00:31:34 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    Span largeSpan(10000);
    for (int i = 0; i < 10000; ++i) {
        largeSpan.addNumber(i * 2);
    }
    
    try {
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    
    Span sp2 = Span(10);
    std::vector<int> numbers;
    for (int i = 1; i <= 5; ++i) {
        numbers.push_back(i);
    }
    sp2.addNumber(numbers.begin(), numbers.end());

    std::vector<int> moreNumbers;
    for (int i = 6; i <= 10; ++i) {
        moreNumbers.push_back(i);
    }
    sp2.addNumber(moreNumbers.begin(), moreNumbers.end());

    try {
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
