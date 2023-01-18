/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:29:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/18 17:37:30 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

int		check_lst(t_list *lst);
void	execute_rules(char	*rule, t_list **stack_a, t_list **stack_b);
void	rule_sa(int check_a, t_list **stack_a);
void	rule_sb(int check_b, t_list **stack_b);
void	rule_pa(int check_b, t_list **stack_a, t_list **stack_b);
void	rule_pb(int check_a, t_list **stack_a, t_list **stack_b);
void	rule_ra(int check_a, t_list **stack_a);
void	rule_rb(int check_b, t_list **stack_b);
void	rule_rra(int check_a, t_list **stack_a);
void	rule_rrb(int check_b, t_list **stack_b);

#endif
