/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:03:41 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/27 18:04:35 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
  private:
    std::string	_type;
  public:
    Weapon(std::string type);
    ~Weapon(void);
    std::string const &getType(void);
    void setType(std::string type);
};

#endif
