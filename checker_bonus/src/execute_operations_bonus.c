/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:14:49 by moztop            #+#    #+#             */
/*   Updated: 2024/05/16 15:40:47 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static	int	execute_operation(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		double_cast(swap, a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		double_cast(rotate, a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		double_cast(reverse_rotate, a, b);
	else
		return (0);
	return (1);
}

int	execute_line(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (-2);
	while (line)
	{
		if (execute_operation(line, a, b) == 0)
			return (free(line), -1);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
