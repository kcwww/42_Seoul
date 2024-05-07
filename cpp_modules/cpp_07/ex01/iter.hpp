/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:04:43 by chanwoki          #+#    #+#             */
/*   Updated: 2024/05/07 15:11:03 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    for (size_t i = 0; i < length; i++)
        func(array[i]);
    std::cout << "none const version" << std::endl;
}

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T &)) {
    for (size_t i = 0; i < length; i++)
        func(array[i]);
    std::cout << "const version" << std::endl;
}

template <typename T>
void printArray(T &element) {
    std::cout << element << std::endl;
}

template <typename T>
void incrementArray(T &element) {
    element++;
}

#endif
