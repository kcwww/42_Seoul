/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:24:22 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/27 17:28:44 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
  private:
    std::string	_name;

  public:
    Zombie(std::string name);
    ~Zombie(void);
    void	announce(void);
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif
