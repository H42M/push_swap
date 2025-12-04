/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:12:23 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 19:01:27 by hgeorges         ###   ########.fr       */
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
		return (-1);
	}
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

static int	input_check(char *av)
{
	char	**tab;
	int		i;

	tab = ft_split(av, ' ');
	i = 0;
	while (tab[i])
	{
		if (!str_check(tab[i]))
			{
				free_tab(tab);
				return (-1);
			}
		i++;
	}
	free_tab(tab);
	return (1);
}

void	add_to_stack(t_list **numbers, char **tab, int *count)
{
	t_list	*new;
	int i;

	i = 0;
	while (tab[i])
	{
		new = ft_lstnew(ft_atol(tab[i]));
		ft_lstadd_back(numbers, new);
		i++;
		(*count)++;
	}
}

t_stack	*parse_input(int ac, char **av, t_ope *s_ope)
{
	t_list	*numbers = NULL;
	int		i;
	int		count;

	if (ac < 2)
		exit(1);
	i = 1;
	count = 0;
	init_flags(s_ope);
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
			flag_check(av[i], s_ope);
		else if (input_check(av[i]))
			add_to_stack(&numbers, ft_split(av[i], ' '), &count);
		else
		error_handler();
		i++;
	}
	if (s_ope->adaptive + s_ope->simple + s_ope->medium + s_ope->complex > 1)
		error_handler();
	if (s_ope->adaptive + s_ope->simple + s_ope->medium + s_ope->complex == 0)
		s_ope->adaptive = 1;
	if (!duplicates_check(numbers))
		error_handler();
	return (init_stack(&numbers, count));
}
