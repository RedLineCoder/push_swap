/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:00:14 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:24:58 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static	void	push_stack(char **args, t_stack *a, t_stack *b, int value)
{
	t_list	*new;
	int		*temp;

	temp = (int *)malloc(sizeof(int));
	if (!temp)
		exit_error(args, a, b);
	*temp = value;
	if (a->top == NULL)
	{
		a->top = ft_lstnew(temp);
		a->count += 1;
	}
	else
	{
		new = ft_lstnew(temp);
		ft_lstadd_back(&a->top, new);
		a->count += 1;
	}
}

static	void	check_duplicate(char **args, t_stack *a, t_stack *b, int value)
{
	t_list	*ptr;

	if (a->top == NULL)
		return ;
	ptr = a->top;
	while (ptr != NULL)
	{
		if (*(int *)(ptr->content) == value)
			exit_error(args, a, b);
		ptr = ptr->next;
	}
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->count = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		ft_lstclear(&stack->top, free);
		free(stack);
	}
}

void	init_stack(t_stack *a, t_stack *b, char **args)
{
	int	loop;
	int	value;

	loop = 0;
	value = 0;
	while (args[loop])
	{
		if (ft_atol(args[loop]) > 2147483647
			|| ft_atol(args[loop]) < -2147483648)
			exit_error(args, a, b);
		value = ft_atoi(args[loop]);
		check_duplicate(args, a, b, value);
		push_stack(args, a, b, value);
		loop++;
	}
}
