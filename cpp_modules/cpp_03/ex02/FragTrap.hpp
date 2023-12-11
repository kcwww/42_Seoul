/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:18:56 by chanwoki          #+#    #+#             */
/*   Updated: 2023/12/11 19:34:19 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap & src);
    ~FragTrap(void);
    FragTrap	&operator=(const FragTrap & rhs);
    void	highFivesGuys(void);
};


#endif
