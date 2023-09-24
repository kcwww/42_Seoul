/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:08:51 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/24 14:31:08 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
  std::string command;

  PhoneBook phonebook;

  while (true)
  {
    std::cout << "Enter a command: " << std::endl;
    std::cin >> command;
    if (command == "ADD")
      phonebook.addContact();
    else if (command == "SEARCH")
      phonebook.searchContact();
    else if (command == "EXIT")
      break;
    else
      std::cout << "Invalid command" << std::endl;
  }
  return (0);
}
