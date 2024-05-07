/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:05:18 by chanwoki          #+#    #+#             */
/*   Updated: 2024/05/07 15:08:16 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    // non const version
    int intArr[] = {1, 2, 3};
    char strArr[] = {'a', 'b', 'c'};
    size_t intArrLength = sizeof(intArr) / sizeof(intArr[0]);
    size_t strArrLength = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "<<< BEFORE VALUE >>>" << std::endl << std::endl;
    
    std::cout << "integer array" << std::endl;
    iter(intArr, intArrLength, printArray);
    std::cout << std::endl;

    std::cout << "string array" << std::endl;
    iter(strArr, strArrLength, printArray);
    std::cout << std::endl;

    iter(intArr, intArrLength, incrementArray);
    iter(strArr, strArrLength, incrementArray);
    std::cout << std::endl;

    std::cout << "<<< AFTER VALUE >>>" << std::endl << std::endl;
    
    std::cout << "integer array" << std::endl;
    iter(intArr, intArrLength, printArray);
    std::cout << std::endl;

    std::cout << "string array:" << std::endl;
    iter(strArr, strArrLength, printArray);
    std::cout << std::endl;

    std::cout << "**********************DONE NONE CONST***************************" << std::endl << std::endl;
    const int const_intArr[] = {1, 2, 3};
    const char const_strArr[] = {'a', 'b', 'c'};

    size_t const_intArrLength = sizeof(const_intArr) / sizeof(const_intArr[0]);
    size_t const_strArrLength = sizeof(const_strArr) / sizeof(const_strArr[0]);
        
    std::cout << "const_integer array" << std::endl;
    iter(const_intArr, const_intArrLength, printArray);
    std::cout << std::endl;
    
    std::cout << "const_string array" << std::endl;
    iter(const_strArr, const_strArrLength, printArray);
    std::cout << std::endl;

    return 0;
}
