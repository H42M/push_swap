/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:12:23 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 14:29:31 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	input_check(char *av)
{
	char	**tab;
	int		i;
	int		j;

	tab = ft_split(av, ' ');
	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][0] == '+' || tab[i][0] == '-')
			j = 1;
		if (!tab[i][j])
		{
			free_tab(tab);
			return (-1);
		}
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
			{
				free_tab(tab);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free_tab(tab);
	return (1);
}

t_list	*parse_input(int ac, char **av)
{
	t_ope	*s_ope;
	t_list	*stack_a;
	int		i;
	char	**tab;

	i = 1;
	s_ope = malloc(sizeof(t_ope));
	if (!s_ope)
		return (NULL);
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
			flag_check(ac, av[i], s_ope);
		else if (input_check(av[i]))
		{
			tab = ft_split(av[i], ' ');
			stack_a = init_stack(tab);
			if (!duplicates_check(stack_a))
				error_handler();
		}
		else
			error_handler();
		i++;
	}
	return (stack_a);
}
