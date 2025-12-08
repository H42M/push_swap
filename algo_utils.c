/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:50:09 by epetrill          #+#    #+#             */
/*   Updated: 2025/12/08 13:03:09 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

int	lst_is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

float	calculate_disorder(t_list *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*next;

	mistakes = 0;
	total_pairs = 0;
	while (stack)
	{
		next = stack->next;
		while (next)
		{
			if (stack->content > next->content)
				mistakes++;
			total_pairs++;
			next = next->next;
		}
		stack = stack->next;
	}
	if (total_pairs == 0)
		return (100.00);
	return ((float)mistakes / (float)total_pairs);
}

int	ft_isqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i);
}
