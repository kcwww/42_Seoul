/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:18:15 by chanwoki          #+#    #+#             */
/*   Updated: 2024/05/19 23:48:24 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try {
        Array<int> intArray(5);

        std::cout << "original digit array: " << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        Array<int> copyArray(intArray);
        copyArray[0] = -10;
        copyArray[3] = -30;

        std::cout << "copied array: " << std::endl;
        for (size_t i = 0; i < copyArray.size(); ++i) {
            std::cout << copyArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "original digit array: " << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        Array<int> assignArray = intArray;
        assignArray[0] = 100;

        std::cout << "assignment array: " << std::endl;
        for (size_t i = 0; i < assignArray.size(); ++i) {
            std::cout << assignArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "original digit array: " << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        const Array<int> constArray(intArray); 

        std::cout << "const array: " << std::endl;
        for (size_t i = 0; i < constArray.size(); ++i) {
            std::cout << constArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << intArray[100] << std::endl; 
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
