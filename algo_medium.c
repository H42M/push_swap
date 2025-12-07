/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:57:05 by epetrill          #+#    #+#             */
/*   Updated: 2025/12/07 19:26:21 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

static void	ft_rotate_to_top(t_stack *stack, int idx, int is_a, t_ope *ope)
{
	if (idx <= stack->size / 2)
	{
		while (idx-- > 0)
			rotate(stack, NULL, is_a, ope);
	}
	else
	{
		while (idx++ < stack->size)
			r_rotate(stack, NULL, is_a, ope);
	}
}

static void	ft_push_chunk(t_stack *a, t_stack *b, int range[2], t_ope *ope)
{
	int	pos;

	pos = find_in_range(a->top, range[0], range[1]);
	if (pos != -1)
	{
		ft_rotate_to_top(a, pos, 0, ope);
		push(a, b, 1, ope);
	}
}

static void	ft_push_chunks(t_stack *a, t_stack *b, t_ope *ope)
{
	int	minmax[2];
	int	chunk;
	int	range[2];
	int	sz;

	ft_find_min_max(a->top, &minmax[0], &minmax[1]);
	sz = ft_isqrt(a->size);
	chunk = 0;
	while (a->size > 3)
	{
		range[0] = minmax[0] + (chunk * (minmax[1] - minmax[0]) / sz);
		range[1] = minmax[0] + ((chunk + 1) * (minmax[1] - minmax[0]) / sz);
		ft_push_chunk(a, b, range, ope);
		if (find_in_range(a->top, range[0], range[1]) == -1)
		{
			chunk++;
			if (chunk >= sz)
				break ;
		}
	}
}

static void	ft_push_back(t_stack *a, t_stack *b, t_ope *ope)
{
	while (b->size > 0)
		push(b, a, 0, ope);
}

void	ft_chunk_sort(t_stack *a, t_stack *b, t_ope *ope)
{
	if (lst_is_sorted(a->top) || a->size <= 3)
	{
		if (a->size <= 3)
			ft_min_sort(a, b, ope);
		return ;
	}
	ft_push_chunks(a, b, ope);
	ft_push_back(a, b, ope);
	ft_min_sort(a, b, ope);
}
