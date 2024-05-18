/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:52:42 by moztop            #+#    #+#             */
/*   Updated: 2024/05/16 18:47:54 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(char **args, t_stack *a, t_stack *b)
{
	if (a)
	{
		ft_lstclear(&a->top, free);
		free(a);
	}
	if (b)
	{
		ft_lstclear(&b->top, free);
		free(b);
	}
	if (args)
		ft_cleanargs(args);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static	char	**argument_parse(int argc, char **argv)
{
	char	**argparse;
	int		loop;

	loop = 1;
	if (!argv || !argc)
		return (NULL);
	if (argc == 2)
		argparse = ft_split(argv[1], ' ');
	else
	{
		argparse = (char **)malloc(sizeof(char *) * argc);
		if (!argparse)
			return (NULL);
		argparse[argc - 1] = NULL;
		while (loop < argc)
		{
			argparse[loop - 1] = ft_strdup(argv[loop]);
			loop++;
		}
	}
	if (!argparse[0])
		return (ft_cleanargs(argparse), NULL);
	return (argparse);
}

static	int	check_param(char *arg)
{
	int	loop;
	int	num;

	loop = 0;
	num = ft_atoi(arg);
	while (arg[loop])
	{
		if (!(ft_isdigit(arg[loop]) || arg[loop] == '+' || arg[loop] == '-'))
			return (0);
		if (loop > 0)
			if ((arg[loop] == '+' || arg[loop] == '-') && arg[loop - 1])
				return (0);
		if ((arg[loop] == '+' || arg[loop] == '-') && !arg[loop + 1])
			return (0);
		if (num == 0 && ft_strncmp(arg, "0", ft_strlen(arg)) != 0)
			return (0);
		loop++;
	}
	return (1);
}

static	void	check_params(char **args, t_stack *a, t_stack *b)
{
	int	loop;

	loop = 0;
	while (args[loop] != NULL)
	{
		if (!check_param(args[loop]))
			exit_error(args, a, b);
		loop++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	if (argc < 2 || !argv)
		return (0);
	a = new_stack();
	b = new_stack();
	args = argument_parse(argc, argv);
	if (!args)
		exit_error(NULL, a, b);
	check_params(args, a, b);
	init_stack(a, b, args);
	sort_stack(a, b);
	ft_lstclear(&a->top, free);
	ft_cleanargs(args);
	free(a);
	free(b);
}
