/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:10:04 by chanwoki          #+#    #+#             */
/*   Updated: 2023/10/29 11:11:00 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "Amateria.hpp"

class MateriaSource : public IMateriaSource
{
  private:
    AMateria *_materia[4];
    int _nbMateria;
  public:
    MateriaSource(void);
    MateriaSource(MateriaSource const &);
    virtual ~MateriaSource(void);

    MateriaSource &operator=(MateriaSource const &);

    virtual void learnMateria(AMateria *);
    virtual AMateria *createMateria(std::string const & type);
}

#endif
