/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:56:45 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:09:16 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "Amateria.hpp"
# include "ICharacter.hpp"

class Cure : public Amateria
{
  public:
    Cure(void);
    Cure(Cure const &);
    virtual ~Cure(void);

    Cure &operator=(Cure const &);

    virtual Amateria *clone(void) const;
    virtual void use(ICharacter & target);
};

#endif
