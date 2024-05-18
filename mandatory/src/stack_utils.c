/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:07:01 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:28:21 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	find_index(t_stack *stack, t_list *target)
{
	t_list	*ptr;
	int		index;

	if (!stack || !target)
		return (0);
	ptr = stack->top;
	index = 1;
	while (ptr != NULL)
	{
		if (ptr == target)
			return (index);
		ptr = ptr->next;
		index++;
	}
	return (0);
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

t_list	*find_max(t_list *lst)
{
	t_list	*ptr;
	t_list	*max;

	if (!lst)
		return (0);
	ptr = lst;
	max = ptr;
	while (ptr != NULL)
	{
		if (*(int *)ptr->content > *(int *)max->content)
			max = ptr;
		ptr = ptr->next;
	}
	return (max);
}

t_list	*find_min(t_list *lst)
{
	t_list	*ptr;
	t_list	*min;

	if (!lst)
		return (0);
	ptr = lst;
	min = ptr;
	while (ptr != NULL)
	{
		if (*(int *)ptr->content < *(int *)min->content)
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}
