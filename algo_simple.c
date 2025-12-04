/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:48:22 by epetrill          #+#    #+#             */
/*   Updated: 2025/12/04 23:32:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "printf/ft_printf.h"

int	ft_is_stack_min(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_min_index(t_list *stack)
{
	int	min;
	int	index;
	int	i;

	min = stack->content;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

void	ft_min_sort(t_stack *stack_a, t_stack *stack_b, t_ope *ope)
{
	ft_printf(1, "Debut du tri\n\n");
	if (stack_a->size <= 2)
	{
		if (!lst_is_sorted(stack_a->top))
			swap(stack_a, stack_b, 0, ope);
	}
	else if (stack_a->size >= 3)
	{
		ft_printf(1, "Debut du tri\n\n");
		while (!lst_is_sorted(stack_a->top))
		{
			while (ft_is_stack_min(stack_a->top) == 0)
			{
				if (ft_min_index(stack_a->top) > stack_a->size / 2)
					r_rotate(stack_a, stack_b, 0, ope);
				else if (ft_min_index(stack_a->top) <= stack_a->size / 2)
					rotate(stack_a, stack_b, 0, ope);
			}
			push(stack_a, stack_b, 1, ope);
		}
		while (stack_b->size > 0)
			push(stack_b, stack_a, 0, ope);
	}
}
