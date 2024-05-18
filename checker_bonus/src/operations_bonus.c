/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:09:10 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:24:54 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	swap(t_stack *stack)
{
	t_list	*ptr;

	ptr = NULL;
	if (stack->count > 1)
	{
		ptr = stack->top->next;
		stack->top->next = ptr->next;
		ptr->next = stack->top;
		stack->top = ptr;
	}
}

void	push(t_stack *to, t_stack *from)
{
	t_list	*ptr;

	ptr = NULL;
	if (from->count > 0)
	{
		ptr = from->top;
		from->top = ptr->next;
		ptr->next = to->top;
		to->top = ptr;
	}
	to->count += 1;
	from->count -= 1;
}

void	rotate(t_stack *stack)
{
	t_list	*ptr;

	ptr = NULL;
	if (stack->count > 1)
	{
		ptr = stack->top->next;
		ft_lstlast(stack->top)->next = stack->top;
		stack->top->next = NULL;
		stack->top = ptr;
	}
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*ptr;

	ptr = NULL;
	if (stack->count > 1)
	{
		ptr = ft_lstlast(stack->top);
		ptr->next = stack->top;
		ft_lstbefore(stack->top, ptr)->next = NULL;
		stack->top = ptr;
	}
}

void	double_cast(void (*operation)(t_stack *),
t_stack *a, t_stack *b)
{
	(*operation)(a);
	(*operation)(b);
}
