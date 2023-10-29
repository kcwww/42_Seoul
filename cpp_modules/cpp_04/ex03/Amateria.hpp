/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:54:09 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/29 11:10:50 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class Amateria
{
  protected:
    std::string _type;
    unsigned int _xp;
  public:
    Amateria(std::string const & type);
    Amateria(Amateria const &);
    virtual ~Amateria(void);

    Amateria &operator=(Amateria const &);

    std::string const & getType(void) const;
    unsigned int getXP(void) const;

    virtual Amateria *clone(void) const = 0;
    virtual void use(ICharacter & target);
}

#endif
