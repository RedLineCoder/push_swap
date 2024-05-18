/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:36:32 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:28:07 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	multi_rotate(int ma, int mb, t_stack *a, t_stack *b)
{
	int	loop;

	loop = 0;
	while (loop < ma && loop < mb)
	{
		double_cast(rotate, a, b, "rr");
		loop++;
	}
	while (loop < ma)
	{
		rotate(a, "ra");
		loop++;
	}
	while (loop < mb)
	{
		rotate(b, "rb");
		loop++;
	}
}

static	void	multi_reverse_rotate(int ma, int mb, t_stack *a, t_stack *b)
{
	int	loop;

	loop = 0;
	while (loop < ma && loop < mb)
	{
		double_cast(reverse_rotate, a, b, "rrr");
		loop++;
	}
	while (loop < ma)
	{
		reverse_rotate(a, "rra");
		loop++;
	}
	while (loop < mb)
	{
		reverse_rotate(b, "rrb");
		loop++;
	}
}

static	void	execute_calculation(t_calc *c, t_stack *a, t_stack *b)
{
	if (c->r_case == RR)
		multi_rotate(c->ra, c->rb, a, b);
	else if (c->r_case == RRR)
		multi_reverse_rotate(c->rra, c->rrb, a, b);
	else if (c->r_case == RA_RRB)
	{
		multi_rotate(c->ra, 0, a, b);
		multi_reverse_rotate(0, c->rrb, a, b);
	}
	else if (c->r_case == RB_RRA)
	{
		multi_rotate(0, c->rb, a, b);
		multi_reverse_rotate(c->rra, 0, a, b);
	}
}

void	sort_complex(t_stack *a, t_stack *b)
{
	t_calc	*c;

	c = NULL;
	while (a->count)
	{
		c = calc_optimum(a, b);
		execute_calculation(c, a, b);
		free(c);
		push(b, a, "pb");
	}
	while (b->count)
		push(a, b, "pa");
	if (find_index(a, find_min(a->top)) < a->count / 2)
		while (a->top != find_min(a->top))
			rotate(a, "ra");
	else
		while (a->top != find_min(a->top))
			reverse_rotate(a, "rra");
}
