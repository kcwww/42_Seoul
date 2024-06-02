/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:48:36 by dkham             #+#    #+#             */
/*   Updated: 2024/06/03 01:38:39 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Usage: ./RPN <expression>\n";
        return 1;
    }
    
    RPN calculator;
    try {
        
        int result = calculator.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }    

    return 0;
}
