/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcw <kcw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:24:56 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/31 14:08:55 by kcw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"

typedef struct s_deque
{
	int				content;
	struct s_deque	*next;
	struct s_deque	*previous;
}	t_deque;

typedef struct s_num
{
	int		temp;
	int		compare;
	int		hi;
	int		ti;
}	t_num;

typedef struct s_ps
{
	t_deque	*head;
	t_deque	*tail;
	t_deque	*lst;
}	t_ps;

int		check_arg(int argc, char **argv);
int		check_sorting_bonus(t_ps *a, t_ps *b);
void	ft_dequeclear(t_ps *deque);
int		ft_strcmp(const char *s1, const char *s2);
void	execute_rules(char *rule, t_ps *a, t_ps *b);
int		check_lst(t_ps *lst);
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
int		init_deque(int argc, char **argv, t_ps *a);
int		check_str(char *rule);
int		check_rules(char *rule);
void	free_str(char **line);
char	*remove_newline(char *rule);

#endif
