/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
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
** Strategy Selection - Executes the appropriate sorting algorithm
** Based on flags set by parse_flags.c:
** --simple → ft_min_sort() O(n²)
** --medium → ft_chunk_sort() O(n√n)
** --complex → ft_complex_sort() O(n log n)
** --adaptive or default → ft_adaptive_sort() (disorder-based selection)
*/

void	execute_strategy(t_stack *a, t_stack *b, t_ope *ope)
{
	if (ope->simple)
		ft_min_sort(a, b, ope);
	else if (ope->medium)
		ft_chunk_sort(a, b, ope);
	else if (ope->complex)
		ft_complex_sort(a, b, ope);
	else
		ft_adaptive_sort(a, b, ope);
}
