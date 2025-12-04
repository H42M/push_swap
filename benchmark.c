/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:00:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 14:00:00 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Benchmark Output - Display performance metrics when --bench flag is used
** Output to stderr (fd=2):
** - Disorder percentage (XX.XX%)
** - Strategy name and complexity class
** - Total operation count
** - Individual operation counts (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
*/

void	print_benchmark(t_ope *ope, float disorder, char *strategy)
{
	int	total;

	// Calculate total operations
	total = ope->count_sa + ope->count_sb + ope->count_ss;
	total += ope->count_pa + ope->count_pb;
	total += ope->count_ra + ope->count_rb + ope->count_rr;
	total += ope->count_rra + ope->count_rrb + ope->count_rrr;
	
	// Print to stderr (fd=2)
	ft_printf("[bench] disorder: %.2f%%\n", 2, disorder * 100);
	ft_printf("[bench] strategy: %s\n", 2, strategy);
	ft_printf("[bench] total_ops: %d\n", 2, total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", 2,
		ope->count_sa, ope->count_sb, ope->count_ss, ope->count_pa, ope->count_pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", 2,
		ope->count_ra, ope->count_rb, ope->count_rr, ope->count_rra, ope->count_rrb, ope->count_rrr);
}
