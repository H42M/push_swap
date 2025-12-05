/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:00:00 by Hugo              #+#    #+#             */
/*   Updated: 2025/12/05 12:11:03 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"

void	free_tab(char **arr)
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

int	str_check(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '+' || av[0] == '-')
		i = 1;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	input_check(char *av)
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
