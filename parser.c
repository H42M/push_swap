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

static void	free_tab(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	str_check(char *av)
{
	int i;
	
	i = 0;
	if (av[0] == '+' || av[0] == '-')
		i = 1;
	if (!av[i])
	{
		return (0);
	}
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	input_check(char *av)
{
	char	**tab;
	int		i;

	if (!av || !av[0])
		return (0);
	tab = ft_split(av, ' ');
	if (!tab || !tab[0])
	{
		if (tab)
			free_tab(tab);
		return (0);
	}
	i = 0;
	while (tab[i])
	{
		if (!str_check(tab[i]))
			{
				free_tab(tab);
				return (0);
			}
		i++;
	}
	free_tab(tab);
	return (1);
}

t_stack	*parse_input(int ac, char **av, t_ope *s_ope)
{
	t_list	*numbers = NULL;
	int		i;
	int		count;
	char **tab;

	if (ac < 2)
		exit(1);
	i = 1;
	count = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
			flag_check(av[i], s_ope);
		else if (input_check(av[i]))
		{
			tab = ft_split(av[i], ' ');
			if (!add_to_stack(&numbers, tab, &count))
			{
				free_tab(tab);
				if (numbers)
					ft_lstclear(&numbers, NULL);
				error_handler();
			}
			free_tab(tab);
		}
		else
		{
			if (numbers)
				ft_lstclear(&numbers, NULL);
			error_handler();
		}
		i++;
	}
	if (s_ope->adaptive + s_ope->simple + s_ope->medium + s_ope->complex > 1)
	{
		if (numbers)
			ft_lstclear(&numbers, NULL);
		error_handler();
	}
	if (s_ope->adaptive + s_ope->simple + s_ope->medium + s_ope->complex == 0)
		s_ope->adaptive = 1;
	if (!duplicates_check(numbers))
	{
		ft_lstclear(&numbers, NULL);
		error_handler();
	}
	return (init_stack(&numbers, count));
}
