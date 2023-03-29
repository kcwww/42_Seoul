/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:00:38 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/30 03:11:46 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char    *remove_newline(char *rule)
{
    int     len;
    int     idx;
    char    *str;

    len = ft_strlen(rule);
    idx = 0;
    str = (char *)malloc(sizeof(char) * len);
    if (str == NULL)
    {
        free(rule);
        return (NULL);
    }
    str[len - 1] = 0;
    while (idx + 1 < len)
    {
        str[idx] = rule[idx];
        idx++;
    }
    free_str(&rule);
    return (str);
}

char    *check_str(char *rule)
{
    int len;

    len = ft_strlen(rule);
    if (len > 4 || len == 0)
    {
        free(rule);
        return (NULL);
    }
    if (rule[len - 1] == '\n')
    {
        rule = remove_newline(rule);
        if (rule == NULL)
            return (NULL);
    }
    if (check_rules(rule))
        return (rule);
    return (NULL);
}