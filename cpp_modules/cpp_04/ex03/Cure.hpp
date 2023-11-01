/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:56:45 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:57:31 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
  public:
    Cure(void);
    Cure(Cure const &);
    virtual ~Cure(void);

    Cure &operator=(Cure const &);

    virtual AMateria *clone(void) const;
    virtual void use(ICharacter & target);
};

#endif
