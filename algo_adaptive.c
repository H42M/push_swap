/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:00:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 14:00:00 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

/*
** Adaptive Sorting Algorithm - Selects strategy based on disorder metric
** disorder < 0.2 → Use O(n) method (nearly sorted optimization)
** 0.2 ≤ disorder < 0.5 → Use O(n√n) method (ft_chunk_sort)
** disorder ≥ 0.5 → Use O(n log n) method (ft_complex_sort)
** Default algorithm when no flag specified or --adaptive flag used
*/

void	ft_adaptive_sort(t_stack *a, t_stack *b, t_ope *ope)
{
	float	disorder;

	disorder = calculate_disorder(a->top);
	if (disorder < 0.2)
	{
		// TODO: Implement O(n) nearly-sorted optimization
		ft_min_sort(a, b);
	}
	else if (disorder < 0.5)
	{
		ft_chunk_sort(a, b);
	}
	else
	{
		ft_complex_sort(a, b, ope);
	}
}
