/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:09:37 by moztop            #+#    #+#             */
/*   Updated: 2024/05/16 18:48:23 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

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

static	void	print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && !b->count)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		state;

	if (argc < 2 || !argv)
		return (0);
	a = new_stack();
	b = new_stack();
	args = argument_parse(argc, argv);
	if (!args)
		exit_error(NULL, a, b);
	check_params(args, a, b);
	init_stack(a, b, args);
	state = execute_line(a, b);
	if (state == -1)
		return (exit_error(args, a, b), 3);
	else if (state == -2)
		return (print_result(a, b), free_stack(a),
			free_stack(b), ft_cleanargs(args), 3);
	ft_cleanargs(args);
	print_result(a, b);
	free_stack(a);
	free_stack(b);
}
