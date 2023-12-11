/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:48:37 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/11 20:14:08 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
  private:
    static const unsigned int _ideasSize = 100;
    std::string _ideas[_ideasSize];

  public:
    Brain();
    Brain(const Brain& ref);
    ~Brain();
    Brain&	operator=(const Brain& ref);
};

#endif
