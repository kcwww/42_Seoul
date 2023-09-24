/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:49:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/24 14:32:06 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
    Contact   _contacts[8];
    int       _nbContacts = 0;
    int       size = 0;
  public:
    PhoneBook(void);
    void		addContact(void);
    void		searchContact(void);
    void    exitContact(void);
    ~PhoneBook(void);
};

#endif
