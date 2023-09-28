/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:13:56 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/28 16:42:52 by chanwoki         ###   ########.fr       */
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
  std::string levelTab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  int idx = -1;
  for (int i = 0; i < 4; i++)
  {
    if (level == levelTab[i])
      idx = i;
  }
  switch (idx)
  {
    case 0:
      (this->*ptr[0])();
      std::cout << std::endl;
    case 1:
      (this->*ptr[1])();
      std::cout << std::endl;
    case 2:
      (this->*ptr[2])();
      std::cout << std::endl;
    case 3:
      (this->*ptr[3])();
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
      break;
  }

}

void Harl::_debug(void)
{
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
  return ;
}

void Harl::_info(void)
{
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put \
enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
  return ;
}

void Harl::_warning(void)
{
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

