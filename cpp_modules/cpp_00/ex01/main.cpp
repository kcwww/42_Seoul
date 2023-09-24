/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:08:51 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/24 15:49:02 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
  std::string command;

  PhoneBook phonebook;

  while (true)
  {
    std::cout << "Enter a command: " << std::flush;
    std::cin >> command;
    if (std::cin.eof())
    {
      std::cout << "Entered EOF" << std::endl;
      exit(0);
    }
    else if (command == "ADD")
      phonebook.addContact();
    else if (command == "SEARCH")
      phonebook.searchContact();
    else if (command == "EXIT")
    {
      phonebook.exitContact();
      break;
    }
    else
      std::cout << "Invalid command" << std::endl;
  }
  return (0);
}
