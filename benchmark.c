/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:00:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/07 19:06:04 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "printf/ft_printf.h"

char	*get_strategy_name(t_ope *ope, float disorder)
{
	if (ope->simple)
		return ("Simple / O(n^2)");
	else if (ope->medium)
		return ("Medium / O(n√n)");
	else if (ope->complex)
		return ("Complex / O(n log n)");
	else
	{
		if (disorder < 0.2)
			return ("Adaptive / O(n)");
		else if (disorder < 0.5)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(n log n)");
	}
}

void	ft_print_benchmark(t_ope *ope, float disorder)
{
	int	total;

	total = ope->count_sa + ope->count_sb + ope->count_ss;
	total += ope->count_pa + ope->count_pb;
	total += ope->count_ra + ope->count_rb + ope->count_rr;
	total += ope->count_rra + ope->count_rrb + ope->count_rrr;
	ft_printf(2, "[bench] disorder: %f%%\n", disorder * 100);
	ft_printf(2, "[bench] strategy: %s\n", get_strategy_name(ope, disorder));
	ft_printf(2, "[bench] total_ops: %d\n", total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ope->count_sa, ope->count_sb, ope->count_ss,
		ope->count_pa, ope->count_pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ope->count_ra, ope->count_rb, ope->count_rr,
		ope->count_rra, ope->count_rrb, ope->count_rrr);
}
