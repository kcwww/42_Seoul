/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:56:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:09:13 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "Amateria.hpp"
# include "ICharacter.hpp"

class Ice : public Amateria
{
  public:
    Ice(void);
    Ice(Ice const &);
    virtual ~Ice(void);

    Ice &operator=(Ice const &);

    virtual Amateria *clone(void) const;
    virtual void use(ICharacter & target);
};

#endif
