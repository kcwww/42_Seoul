/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:49:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/23 19:01:14 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
  private:
    Contact(void);
    std::string	_firstName;
    std::string	_lastName;
    std::string	_nickname;
    std::string	_phoneNumber;
    std::string	_darkestSecret;
  public:
    Contact (
      std::string firstName,
      std::string lastName,
      std::string nickname,
      std::string phoneNumber,
      std::string darkestSecret
    );
    std::string	getFirstName(void);
    std::string	getLastName(void);
    std::string	getNickname(void);
    std::string	getPhoneNumber(void);
    std::string	getDarkestSecret(void);
    ~Contact(void);
};

#endif
