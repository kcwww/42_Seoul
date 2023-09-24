/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:47:51 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/24 13:24:04 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string  Contact::getFirstName(void)
{
  return (this->_firstName);
}

std::string  Contact::getLastName(void)
{
  return (this->_lastName);
}

std::string  Contact::getNickname(void)
{
  return (this->_nickname);
}

std::string  Contact::getPhoneNumber(void)
{
  return (this->_phoneNumber);
}

std::string  Contact::getDarkestSecret(void)
{
  return (this->_darkestSecret);
}

Contact::~Contact(void)
{
  return ;
}
