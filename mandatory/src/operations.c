/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:19:15 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:28:13 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack, char *id)
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
	if (id)
		ft_putendl_fd(id, 1);
}

void	push(t_stack *to, t_stack *from, char *id)
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
	if (id)
		ft_putendl_fd(id, 1);
}

void	rotate(t_stack *stack, char *id)
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
	if (id)
		ft_putendl_fd(id, 1);
}

void	reverse_rotate(t_stack *stack, char *id)
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
	if (id)
		ft_putendl_fd(id, 1);
}

void	double_cast(void (*operation)(t_stack *, char *),
t_stack *a, t_stack *b, char *id)
{
	(*operation)(a, NULL);
	(*operation)(b, NULL);
	ft_putendl_fd(id, 1);
}
