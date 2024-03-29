/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcw <kcw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:19:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/06 09:21:08 by kcw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Replacer
{
  public:
    Replacer(std::string filename, std::string s1, std::string s2);
    ~Replacer(void);
    void replace(void);

  private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
};

#endif
