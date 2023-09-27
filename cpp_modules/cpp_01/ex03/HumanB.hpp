/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:03:33 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/27 18:22:07 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
  private:
    std::string	_name;
    Weapon		*_weapon;
  public:
    HumanB(std::string name);
    ~HumanB(void);
    void attack(void);
    void setWeapon(Weapon &weapon);
};

#endif
