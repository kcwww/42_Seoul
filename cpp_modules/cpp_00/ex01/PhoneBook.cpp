/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:11:51 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/23 16:13:13 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void  PhoneBook::addContact(void)
{
  if (_nbContacts == 8)
    std::cout << "PhoneBook is full" << std::endl;
  else
  {
    _contacts[_nbContacts] = Contact();
    _nbContacts++;
  }
}
