/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:48:22 by epetrill          #+#    #+#             */
/*   Updated: 2025/11/27 04:08:16 by epetrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size <= 2)
	{
		if (!lst_is_sorted(*stack_a))
			swap(stack_a);
	}
	else if (size >= 3)
	{
		while (!lst_is_sorted(*stack_a))
		{
			if ((*stack_a)->content > (*stack_a)->next->content
				&& (*stack_a)->content > ft_lstlast(*stack_a)->content)
				rotate(stack_a);
			else if ((*stack_a)->next->content > (*stack_a)->content
				&& (*stack_a)->next->content > ft_lstlast(*stack_a)->content)
				reverse_rotate(stack_a);
			else
				swap(stack_a);
		}
	}
}