/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:47:31 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 15:09:30 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  private:
    std::string		_mode;
  public:
    ScavTrap(void);
    ScavTrap(const ScavTrap & src);
    ScavTrap(std::string name);
    ~ScavTrap(void);
    ScavTrap &operator=(const ScavTrap & rhs);
    void	attack(std::string const & target);
    void	takeDamage(unsigned int amount);
    void	beRepaired(unsigned int amount);
    void	guardGate(void);
};

#endif
