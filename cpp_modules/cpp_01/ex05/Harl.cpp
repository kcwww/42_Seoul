/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:13:56 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/02 13:48:40 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
  return ;
}

Harl::~Harl(void)
{
  return ;
}

void Harl::complain(std::string level)
{
  void (Harl::*ptr[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
  std::string level_array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++)
  {
    if (level == level_array[i])
      (this->*ptr[i])();
  }
  return ;
}

void Harl::_debug(void)
{
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
  return ;
}

void Harl::_info(void)
{
  std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put \
enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
  return ;
}

void Harl::_warning(void)
{
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

