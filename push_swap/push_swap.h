/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:29:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 03:07:26 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_three
{
	int	min;
	int	max;
	int	mid;
}	t_three;

typedef struct s_rules
{
	int	rra;
	int	ra;
	int	rb;
	int	rrb;
}	t_rules;

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

typedef struct s_num
{
	int		temp;
	int		compare;
	int		hi;
	int		ti;
}	t_num;

int		check_lst(t_ps *lst);
void	execute_rules(char	*rule, t_ps *a, t_ps *b);
void	ft_dequeclear(t_ps *deque);
t_deque	*ft_dequenew(int content);
int		rule_sa(int check_a, t_ps *a);
int		rule_sb(int check_b, t_ps *b);
int		rule_pa(int check_b, t_ps *a, t_ps *b);
int		rule_pb(int check_a, t_ps *a, t_ps *b);
int		rule_ra(int check_a, t_ps *a);
int		rule_rb(int check_b, t_ps *b);
int		rule_rra(int check_a, t_ps *a);
int		rule_rrb(int check_b, t_ps *b);
int		check_int(const char *str);
int		check_arg(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		init_deque(int argc, char **argv, t_ps *a);
int		check_sorting(t_ps *a);
void	set_pivot(t_ps *a, t_ps *b);
int		ft_dequesize(t_deque *lst);
void	sort_three(t_ps *a, t_ps *b);
void	greeding(t_ps *a, t_ps *b);
void	choose_greed(t_ps *a, t_ps *b, int min);
int		counting_rules(t_ps *a, int num, int idx, int flag);
void	go_sorting(t_ps *a, t_ps *b);
void	count_sorting(t_ps *a, int *ra, int *rra);
void	both_big(int pa_num, t_ps *a, t_rules *rule, t_deque *lst);
void	big_and_small(int pa_num, t_ps *a, t_rules *rule);
void	both_small(int pa_num, t_ps *a, t_rules *rule, t_deque *lst);
void	exe_pa(t_ps *a, t_ps *b, int num, t_rules *rules);
void	exe_rr(t_rules *rule, t_ps *a, t_ps *b);
void	ex_both_big(int pa_num, t_ps *a, t_ps *b, t_rules *rule);
void	ex_big_and_small(int pa_num, t_ps *a, t_ps *b, t_rules *rule);
void	ex_both_small(int pa_num, t_ps *a, t_ps *b, t_rules *rule);
void	mid_assist(t_num *num, t_ps *a, int pa_num);

#endif
