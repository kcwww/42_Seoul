/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:48:37 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 18:06:47 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
  private:
    std::string _ideas[100];

  public:
    Brain();
    Brain(const Brain& ref);
    ~Brain();
    Brain&	operator=(const Brain& ref);
    std::string const *getIdeas() const;
};

#endif
