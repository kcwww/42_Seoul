/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:55:47 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 15:47:08 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
  public:
    Harl(void);
    ~Harl(void);
    void complain(std::string level);
  private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
};

#endif
