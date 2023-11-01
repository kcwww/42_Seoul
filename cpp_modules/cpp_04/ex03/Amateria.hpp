/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:54:09 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:58:20 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
  protected:
    std::string _type;

  public:
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(AMateria const &);
    virtual ~AMateria(void);

    AMateria &operator=(AMateria const &);

    std::string const & getType(void) const;


    virtual AMateria *clone(void) const = 0;
    virtual void use(ICharacter & target);
};

#endif
