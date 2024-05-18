/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:02:12 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:25:01 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

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

void	ft_cleanargs(char **table)
{
	int	loop;

	loop = 0;
	while (table[loop])
		free(table[loop++]);
	free(table);
}

int	is_sorted(t_stack *stack)
{
	t_list	*ptr;

	if (!stack || !stack->top)
		return (0);
	ptr = stack->top;
	while (ptr->next != NULL)
	{
		if (!(*(int *)ptr->content < *(int *)ptr->next->content))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	exit_error(char **args, t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	if (args)
		ft_cleanargs(args);
	ft_putendl_fd("Error", 2);
	exit(1);
}
