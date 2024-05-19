/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:33:31 by chanwookim        #+#    #+#             */
/*   Updated: 2024/05/20 00:34:15 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    
    std::cout << "test if copy constructor works: " << std::endl;
    
    MutantStack<int> mstack2(mstack);
    MutantStack<int>::iterator it2 = mstack2.begin();
    MutantStack<int>::iterator ite2 = mstack2.end();

    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    
    std::cout << "test if assignation operator works: " << std::endl;
    
    MutantStack<int> mstack3;
    mstack3 = mstack;
    MutantStack<int>::iterator it3 = mstack3.begin();
    MutantStack<int>::iterator ite3 = mstack3.end();
    
    while (it3 != ite3) {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    

    return 0;
}
