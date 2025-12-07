/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:12:23 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 23:56:18 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "parser.h"
#include "stack.h"

static void	process_arg(char *arg, t_list **numbers)
{
	char	**tab;

	tab = ft_split(arg, ' ');
	if (!add_to_stack(numbers, tab))
	{
		free_tab(tab);
		if (*numbers)
			ft_lstclear(numbers, NULL);
		error_handler();
	}
	free_tab(tab);
}

static void	validate_strategy(t_ope *s_ope, t_list **numbers)
{
	int	strategy_count;

	strategy_count = s_ope->adaptive + s_ope->simple;
	strategy_count += s_ope->medium + s_ope->complex;
	if (strategy_count > 1)
	{
		if (*numbers)
			ft_lstclear(numbers, NULL);
		error_handler();
	}
	if (strategy_count == 0)
		s_ope->adaptive = 1;
	if (!duplicates_check(*numbers))
	{
		ft_lstclear(numbers, NULL);
		error_handler();
	}
}

t_list	*parse_input(int ac, char **av, t_ope *s_ope)
{
	t_list	*numbers;
	int		i;

	if (ac < 2)
		exit(1);
	numbers = NULL;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
			flag_check(av[i], s_ope);
		else if (input_check(av[i]))
			process_arg(av[i], &numbers);
		else
		{
			if (numbers)
				ft_lstclear(&numbers, NULL);
			error_handler();
		}
		i++;
	}
	validate_strategy(s_ope, &numbers);
	return (numbers);
}
