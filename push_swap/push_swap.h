/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:29:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/16 13:50:41 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"



typedef struct s_deque
{
	int				content;
	struct s_deque	*next;
	struct s_deque	*previous;
}	t_deque;

typedef struct s_ps
{
	t_deque	*head;
	t_deque	*tail;
	t_deque	*lst;
}	t_ps;

int		check_lst(t_deque *lst);
void	execute_rules(char	*rule, t_ps *A, t_ps *B);

#endif
