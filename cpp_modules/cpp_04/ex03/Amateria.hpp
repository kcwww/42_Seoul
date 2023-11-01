/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:54:09 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:14:05 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class Amateria
{
  protected:
    std::string _type;

  public:
    Amateria(void);
    Amateria(std::string const & type);
    Amateria(Amateria const &);
    virtual ~Amateria(void);

    Amateria &operator=(Amateria const &);

    std::string const & getType(void) const;


    virtual Amateria *clone(void) const = 0;
    virtual void use(ICharacter & target);
};

#endif
