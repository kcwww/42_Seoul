/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:56:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:57:51 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
  public:
    Ice(void);
    Ice(Ice const &);
    virtual ~Ice(void);

    Ice &operator=(Ice const &);

    virtual AMateria *clone(void) const;
    virtual void use(ICharacter & target);
};

#endif
