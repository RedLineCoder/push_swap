/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:52:46 by moztop            #+#    #+#             */
/*   Updated: 2024/05/16 18:42:19 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

typedef struct s_stack
{
	t_list		*top;
	int			count;
}	t_stack;

typedef enum e_rotate_cases
{
	NONE,
	RR,
	RRR,
	RA_RRB,
	RB_RRA
}	t_rotate_cases;

typedef struct s_calc
{
	t_list			*node_a;
	t_list			*node_b;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				max;
	t_rotate_cases	r_case;
}	t_calc;

void	swap(t_stack *stack, char *id);
void	push(t_stack *to, t_stack *from, char *id);
void	rotate(t_stack *stack, char *id);
void	reverse_rotate(t_stack *stack, char *id);
void	double_cast(void (*operation)(t_stack *, char *),
			t_stack *a, t_stack *b, char *id);
t_calc	*calc_optimum(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
void	init_stack(t_stack *a, t_stack *b, char **args);
int		is_sorted(t_stack *stack);
int		find_index(t_stack *stack, t_list *target);
t_list	*find_max(t_list *lst);
t_list	*find_min(t_list *lst);
t_stack	*new_stack(void);
void	exit_error(char **args, t_stack *a, t_stack *b);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
long	ft_atol(const char *str);
t_list	*ft_lstbefore(t_list *lst, t_list *target);
void	ft_cleanargs(char **table);

#endif