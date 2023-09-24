/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:49:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/24 19:04:49 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
  private:
    Contact   _contacts[8];
    int       _nbContacts;
    int       _size;
  public:
    PhoneBook(void);
    void		addContact(void);
    void		searchContact(void);
    void    exitContact(void);
    void    isNumber(std::string str);
    ~PhoneBook(void);
};

#endif
