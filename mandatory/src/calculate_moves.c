/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:15:53 by moztop            #+#    #+#             */
/*   Updated: 2024/05/15 21:28:04 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	t_calc	*new_calculation(void)
{
	t_calc	*c;

	c = (t_calc *)malloc(sizeof(t_calc));
	if (!c)
		return (NULL);
	c->node_a = NULL;
	c->node_b = NULL;
	c->ra = 0;
	c->rb = 0;
	c->rra = 0;
	c->rrb = 0;
	c->max = 0;
	c->r_case = NONE;
	return (c);
}

static	t_list	*min_max(t_list *list, t_stack *stack)
{
	t_list	*ptr;
	t_list	*min_of_max;

	if (!list || !stack)
		return (NULL);
	ptr = stack->top;
	min_of_max = find_min(stack->top);
	while (ptr != NULL)
	{
		if (*(int *)ptr->content > *(int *)min_of_max->content
			&& *(int *)ptr->content < *(int *)list->content)
			min_of_max = ptr;
		ptr = ptr->next;
	}
	return (min_of_max);
}

static	void	calc_moves(t_calc *c, t_stack *a, t_stack *b)
{
	c->ra = find_index(a, c->node_a) - 1;
	c->rb = find_index(b, c->node_b) - 1;
	c->rra = a->count - find_index(a, c->node_a) + 1;
	c->rrb = b->count - find_index(b, c->node_b) + 1;
	c->max = ft_min(ft_min(ft_max(c->ra, c->rb), ft_max(c->rra, c->rrb)),
			ft_min(c->ra + c->rrb, c->rra + c->rb));
	if (c->max == ft_max(c->ra, c->rb))
		c->r_case = RR;
	else if (c->max == ft_max(c->rra, c->rrb))
		c->r_case = RRR;
	else if (c->max == c->ra + c->rrb)
		c->r_case = RA_RRB;
	else if (c->max == c->rra + c->rb)
		c->r_case = RB_RRA;
}

static	void	init_temp(t_calc *temp, t_list *ptr, t_stack *a, t_stack *b)
{
	temp->node_a = ptr;
	temp->node_b = min_max(temp->node_a, b);
	if (min_max(temp->node_a, b) != NULL)
		if (*(int *)temp->node_b->content > *(int *)temp->node_a->content)
			temp->node_b = find_max(b->top);
	calc_moves(temp, a, b);
}

t_calc	*calc_optimum(t_stack *a, t_stack *b)
{
	t_calc	*temp;
	t_calc	*final;
	t_list	*ptr;
	int		max;

	temp = new_calculation();
	final = new_calculation();
	ptr = a->top;
	max = ft_max(a->count, b->count);
	while (ptr != NULL)
	{
		init_temp(temp, ptr, a, b);
		if (temp->max < max)
		{
			final->node_a = temp->node_a;
			final->node_b = temp->node_b;
			max = temp->max;
		}
		ptr = ptr->next;
	}
	free(temp);
	calc_moves(final, a, b);
	return (final);
}
