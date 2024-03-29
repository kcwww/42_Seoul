/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:10:20 by chanwoki          #+#    #+#             */
/*   Updated: 2023/11/01 16:57:26 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
