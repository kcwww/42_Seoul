/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:57:53 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:18:36 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
    std::string _name;
    Amateria *_inventory[4];

  public:
    Character(std::string const &);
    Character(Character const &);
    virtual ~Character(void);

    Character &operator=(Character const &);

    virtual std::string const & getName(void) const;
    virtual void equip(AMateria * m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter & target);
};

#endif
