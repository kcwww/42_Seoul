/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:47:51 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/24 14:51:59 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
  return ;
}

Contact::Contact(
  std::string firstName,
  std::string lastName,
  std::string nickname,
  std::string phoneNumber,
  std::string darkestSecret
)
{
  this->_firstName = firstName;
  this->_lastName = lastName;
  this->_nickname = nickname;
  this->_phoneNumber = phoneNumber;
  this->_darkestSecret = darkestSecret;
  return ;
}

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
