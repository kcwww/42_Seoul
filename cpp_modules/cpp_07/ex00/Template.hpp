/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:01:26 by chanwoki          #+#    #+#             */
/*   Updated: 2024/01/25 16:01:44 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template <typename T>
void	swap(T &a, T &b)
{
  T tmp;

  tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T		min(T &a, T &b)
{
  if (a < b)
    return a;
  return b;
}

template <typename T>
T		max(T &a, T &b)
{
  if (a > b)
    return a;
  return b;
}

#endif
