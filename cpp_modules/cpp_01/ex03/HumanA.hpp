/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:03:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/27 18:21:35 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
  private:
    std::string	_name;
    Weapon		&_weapon;
  public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);
    void attack(void);
};

#endif
