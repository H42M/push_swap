/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:48:29 by Hugo              #+#    #+#             */
/*   Updated: 2025/12/07 18:55:57 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

void	ft_find_min_max(t_list *stack, int *min, int *max)
{
	*min = stack->content;
	*max = stack->content;
	while (stack)
	{
		if (stack->content < *min)
			*min = stack->content;
		if (stack->content > *max)
			*max = stack->content;
		stack = stack->next;
	}
}

int	is_in_range(int value, int min, int max)
{
	return (value >= min && value <= max);
}

int	find_in_range(t_list *stack, int min, int max)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (is_in_range(stack->content, min, max))
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
