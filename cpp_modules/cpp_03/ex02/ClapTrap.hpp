/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:17:10 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/29 14:51:02 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  protected:
    std::string		_name;
    unsigned int	_hitPoints;
    unsigned int	_energyPoints;
    unsigned int	_attackDamage;
  public:
    ClapTrap(void);
    ClapTrap(const ClapTrap & src);
    ClapTrap(std::string name);
    virtual ~ClapTrap(void);
    ClapTrap &operator=(const ClapTrap & rhs);
    virtual void	attack(std::string const & target);
    void	takeDamage(unsigned int amount);
    void	beRepaired(unsigned int amount);
};

#endif
