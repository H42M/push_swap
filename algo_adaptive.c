/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:00:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/07 23:09:05 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "printf/ft_printf.h"

void	ft_adaptive_sort(t_stack *a, t_stack *b, t_ope *ope, float disorder)
{
	if (disorder < 0.2)
	{
		ft_min_sort(a, b, ope);
	}
	else if (disorder < 0.5)
	{
		ft_chunk_sort(a, b, ope);
	}
	else
	{
		ft_radix_sort(a, b, ope);
	}
}
