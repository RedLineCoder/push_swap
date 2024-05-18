/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:10:03 by moztop            #+#    #+#             */
/*   Updated: 2024/05/16 18:42:46 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../../libft/libft.h"

typedef struct s_stack
{
	t_list		*top;
	int			count;
}	t_stack;

void	exit_error(char **args, t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
void	init_stack(t_stack *a, t_stack *b, char **args);
t_list	*ft_lstbefore(t_list *lst, t_list *target);
long	ft_atol(const char *str);
void	ft_cleanargs(char **table);
t_stack	*new_stack(void);
int		is_sorted(t_stack *stack);
int		execute_line(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	push(t_stack *to, t_stack *from);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	double_cast(void (*operation)(t_stack *),
			t_stack *a, t_stack *b);

#endif