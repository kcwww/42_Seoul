/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:09 by dkham             #+#    #+#             */
/*   Updated: 2024/06/03 01:41:37 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



int main(int argc, char** argv)
{
    PmergeMe pmergeme;
    try
    {
        pmergeme.checkValidInput(argc, argv);

        pmergeme.runSort();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (1);
}
