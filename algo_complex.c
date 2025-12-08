/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:00:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/08 13:41:29 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

static int	find_max_bits(int size)
{
	int	max_bits;
	int	max_nbr;

	max_bits = 0;
	max_nbr = size - 1;
	while ((max_nbr >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	mini_radix_sort(t_stack *a, t_stack *b, t_ope *ope, int i)
{
	int	j;
	int	size;

	j = 0;
	size = a->size;
	while (j < size)
	{
		if ((a->top->content >> i) & 1)
			rotate(a, b, 0, ope);
		else
			push(a, b, 1, ope);
		j++;
	}
	while (b->size > 0)
		push(b, a, 0, ope);
}

void	ft_radix_sort(t_stack *a, t_stack *b, t_ope *ope)
{
	int	max_bits;
	int	i;

	if (lst_is_sorted(a->top))
		return ;
	if (a->size <= 5)
		return (ft_min_sort(a, b, ope));
	index_mapping(a);
	max_bits = find_max_bits(a->size);
	i = -1;
	while (++i < max_bits)
	{
		mini_radix_sort(a, b, ope, i);
	}
}
