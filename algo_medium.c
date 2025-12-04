/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:57:05 by epetrill          #+#    #+#             */
/*   Updated: 2025/12/03 09:10:12 by epetrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Chunk-Based Sorting Algorithm - O(n√n)
** 
** Strategy: Divide elements into √n chunks by value range.
** Process chunks in order, pushing elements to stack_b, then merge back.
** Each chunk is naturally sorted within its value range.
*/

static void	ft_find_min_max(t_list *stack, int *min, int *max)
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

static int	ft_find_chunk_element(t_list *stack, int min, int size, int chunk)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (((stack->content - min) / size) == chunk)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

static void	ft_rotate_to_top(t_stack *a, t_stack *b, int idx)
{
	while (idx > 0)
	{
		if (idx <= a->size / 2)
			rotate(a, b, 0, NULL);
		else
			r_rotate(a, b, 0, NULL);
		idx--;
	}
}

static void	ft_process_chunks(t_stack *a, t_stack *b, int min, int sz)
{
	int	idx;
	int	pos;

	idx = 0;
	while (idx <= (100 / sz) && a->size > 0)
	{
		pos = ft_find_chunk_element(a->top, min, sz, idx);
		if (pos != -1)
		{
			ft_rotate_to_top(a, b, pos);
			push(a, b, 1, NULL);
		}
		idx++;
	}
}

void	ft_chunk_sort(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	sz;

	if (lst_is_sorted(a->top) || a->size <= 3)
	{
		if (a->size <= 3)
			ft_min_sort(a, b);
		return ;
	}
	ft_find_min_max(a->top, &min, &max);
	sz = ft_isqrt(a->size);
	if (sz == 0)
		sz = 1;
	ft_process_chunks(a, b, min, sz);
	while (b->size > 0)
		push(b, a, 0, NULL);
}
