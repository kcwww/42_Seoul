/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:29:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/25 19:41:29 by chanwoki         ###   ########.fr       */
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

int		check_lst(t_ps *lst);
void	execute_rules(char	*rule, t_ps *A, t_ps *B);
void	ft_dequeclear(t_ps *deque);
t_deque	*ft_dequenew(int content);
void	rule_sa(int check_a, t_ps *A);
void	rule_sb(int check_b, t_ps *B);
void	rule_pa(int check_b, t_ps *A, t_ps *B);
void	rule_pb(int check_a, t_ps *A, t_ps *B);
void	rule_ra(int check_a, t_ps *A);
void	rule_rb(int check_b, t_ps *B);
void	rule_rra(int check_a, t_ps *A);
void	rule_rrb(int check_b, t_ps *B);
int		check_int(const char *str);
int		check_arg(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		init_deque(int argc, char **argv, t_ps *A);

#endif
