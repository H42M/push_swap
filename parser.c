/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:12:23 by hgeorges          #+#    #+#             */
/*   Updated: 2025/11/27 04:12:21 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "push_swap.h"

static int	input_check(int argc, char **argv)
{
	int	i;

	while (i < argc)
	{
		while (**argv)
		{
			if (argv != ' ' && (**argv < '0' || **argv > '9'))
				return (-1);
			*argv++;
		}
		i++;
	}
	return (1);
}

static void	print_error(void)
{
	printf("Error\n");
}

int	parse_input(int argc, char **argv)
{
	char	**tab;
	int		i;
	
	if (input_check(argc, argv))
	{
		print_error();
		return (-1);
	}
	i = 0;
	while (argv[i])
	{
		
	}
	return(1);
}
