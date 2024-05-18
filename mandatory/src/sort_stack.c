/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:57:36 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:28:19 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	sort_max_three_args(t_stack *a)
{
	if (a->count == 2)
		swap(a, "sa");
	if (a->count == 3)
	{
		if (a->top == find_min(a->top))
		{
			reverse_rotate(a, "rra");
			swap(a, "sa");
		}
		else if (a->top == find_max(a->top))
		{
			rotate(a, "ra");
			if (!is_sorted(a))
				swap(a, "sa");
		}
		else if (ft_lstlast(a->top) == find_max(a->top))
			swap(a, "sa");
		else
			reverse_rotate(a, "rra");
	}
}

static	void	sort_max_five_args(t_stack *a, t_stack *b)
{
	while (a->count > 3 && !is_sorted(a))
	{
		if (a->top == find_min(a->top))
			push(b, a, "pb");
		else if (find_index(a, find_min(a->top)) - 1 <= a->count / 2)
			rotate(a, "ra");
		else
			reverse_rotate(a, "rra");
	}
	if (!is_sorted(a))
		sort_max_three_args(a);
	while (b->count)
		push(a, b, "pa");
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->count < 2)
		return ;
	if (is_sorted(a))
		return ;
	else if (a->count <= 3)
		sort_max_three_args(a);
	else if (a->count > 3 && a->count <= 5)
		sort_max_five_args(a, b);
	else
		sort_complex(a, b);
}
