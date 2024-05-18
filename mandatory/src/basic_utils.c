/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:59:13 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:27:58 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str <= '\r' && *str >= '\t'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}

t_list	*ft_lstbefore(t_list *lst, t_list *target)
{
	t_list	*ptr;

	if (!lst || !target)
		return (0);
	ptr = lst;
	while (ptr->next != NULL)
	{
		if (ptr->next == target)
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}

void	ft_cleanargs(char **table)
{
	int	loop;

	loop = 0;
	while (table[loop])
		free(table[loop++]);
	free(table);
}
