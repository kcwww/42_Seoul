/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:11:51 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/24 14:29:46 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>

void  PhoneBook::addContact(void)
{
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

  std::cout << "Enter first name: " << std::endl;
  std::cin >> firstName;
  std::cout << "Enter last name: " << std::endl;
  std::cin >> lastName;
  std::cout << "Enter nickname: " << std::endl;
  std::cin >> nickname;
  std::cout << "Enter phone number: " << std::endl;
  std::cin >> phoneNumber;
  std::cout << "Enter darkest secret: " << std::endl;
  std::cin >> darkestSecret;
  Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);

  this->_contacts[this->_nbContacts] = contact;
  this->_nbContacts++;
  this-> size++;
  this->_nbContacts %= 8;
  this->size = this->size > 8 ? 8 : this->size;
}

void PhoneBook::searchContact() {
    if (this->size == 0) {
        std::cout << "Phonebook is empty. Add contacts first." << std::endl;
        return;
    }

    std::cout << "   Index | First Name |  Last Name |  Nickname" << std::endl;
    std::cout << "----------|------------|------------|------------" << std::endl;

    for (int i = 0; i < this->size; ++i) {
        std::string firstName = _contacts[i].getFirstName();
        std::string lastName = _contacts[i].getLastName();
        std::string nickname = _contacts[i].getNickname();

        if (firstName.length() > 10)
            firstName = firstName.substr(0, 10) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 10) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 10) + ".";

        std::cout << std::setw(10) << i + 1 << " | " << std::setw(10) << firstName << " | " << std::setw(10) << lastName << " | " << std::setw(10) << nickname << std::endl;
    }

    int index;
    std::cout << "Enter the index of the entry to display: ";
    std::cin >> index;

    if (index < 1 || index > _nbContacts) {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    } else {
      std::string firstName = _contacts[index - 1].getFirstName();
      std::string lastName = _contacts[index - 1].getLastName();
      std::string nickname = _contacts[index - 1].getNickname();

      if (firstName.length() > 10)
          firstName = firstName.substr(0, 10) + ".";
      if (lastName.length() > 10)
          lastName = lastName.substr(0, 10) + ".";
      if (nickname.length() > 10)
          nickname = nickname.substr(0, 10) + ".";
      std::cout << "Index : " << std::setw(10) << index << std::endl;
      std::cout << "First Name : " << std::setw(10) << firstName << std::endl;
      std::cout << "Last Name : " << std::setw(10) << lastName << std::endl;
      std::cout << "Nickname: " << std::setw(10) << nickname << std::endl;
    }
}

void PhoneBook::exitContact(void)
{
  std::cout << "Exit" << std::endl;

  return ;
}
