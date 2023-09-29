/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:30:47 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 16:38:51 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
    std::string	_name;
  public:
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap & src);
    ~DiamondTrap(void);
    DiamondTrap	&operator=(const DiamondTrap & rhs);
    void	attack(std::string const & target);
    void	whoAmI(void);
    void  status(void);
};

#endif
