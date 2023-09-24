/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:11:51 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/24 15:47:52 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
  this->_nbContacts = 0;
  this->size = 0;
}

void  PhoneBook::addContact(void)
{
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

  std::cout << "Enter first name: " << std::flush;
  std::cin >> firstName;
  if (std::cin.eof())
  {
    std::cout << "Entered EOF" << std::endl;
    exit(0);
  }
  std::cout << "Enter last name: " << std::flush;
  std::cin >> lastName;
  if (std::cin.eof())
  {
    std::cout << "Entered EOF" << std::endl;
    exit(0);
  }
  std::cout << "Enter nickname: " << std::flush;
  std::cin >> nickname;
  if (std::cin.eof())
  {
    std::cout << "Entered EOF" << std::endl;
    exit(0);
  }
  std::cout << "Enter phone number: " << std::flush;
  std::cin >> phoneNumber;
  if (std::cin.eof())
  {
    std::cout << "Entered EOF" << std::endl;
    exit(0);
  }
  this->isNumber(phoneNumber);
  std::cout << "Enter darkest secret: " << std::flush;
  std::cin >> darkestSecret;
  if (std::cin.eof())
  {
    std::cout << "Entered EOF" << std::endl;
    exit(0);
  }
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

    std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i = 0; i < this->size; ++i) {
        std::string firstName = _contacts[i].getFirstName();
        std::string lastName = _contacts[i].getLastName();
        std::string nickname = _contacts[i].getNickname();

        if (firstName.length() > 10)
          firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
          lastName = lastName.substr(0, 9) + ".";
        if (nickname.length() > 10)
          nickname = nickname.substr(0, 9) + ".";

        std::cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nickname << "|" << std::endl;
    }

    int index;
    std::cout << "Enter the index of the entry to display: ";
    std::cin >> index;
    if (std::cin.eof())
    {
      std::cout << "Entered EOF" << std::endl;
      exit(0);
    }
    if (index < 1 || index > _nbContacts) {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    } else {
      std::string firstName = _contacts[index - 1].getFirstName();
      std::string lastName = _contacts[index - 1].getLastName();
      std::string nickname = _contacts[index - 1].getNickname();
      std::string phoneNumber = _contacts[index - 1].getPhoneNumber();

      std::cout << "Index : " << index << std::endl;
      std::cout << "First Name : " << firstName << std::endl;
      std::cout << "Last Name : " << lastName << std::endl;
      std::cout << "Nickname: " << nickname << std::endl;
      std::cout << "Phone Number: " << phoneNumber << std::endl;
    }
}

void PhoneBook::exitContact(void)
{
  std::cout << "Exit" << std::endl;

  return ;
}

void  PhoneBook::isNumber(std::string str)
{
  int i = 0;

  while (str[i])
  {
    if (isdigit(str[i]) == false)
    {
      std::cout << "Invalid input" << std::endl;
      exit(0);
    }
    i++;
  }
}

PhoneBook::~PhoneBook(void)
{
  return ;
}
