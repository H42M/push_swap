/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:55:38 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/05 00:08:49 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "printf/ft_printf.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_ope	*s_ope;
	t_list	*current;

	s_ope = init_ope();
	stack = parse_input(argc, argv, s_ope);
	if (!stack)
		return (1);
	ft_printf(1, "=== FLAGS STATUS ===\n");
	ft_printf(1, "simple: %d\n", s_ope->simple);
	ft_printf(1, "medium: %d\n", s_ope->medium);
	ft_printf(1, "complex: %d\n", s_ope->complex);
	ft_printf(1, "adaptive: %d\n", s_ope->adaptive);
	ft_printf(1, "bench: %d\n", s_ope->bench);
	ft_printf(1, "\n=== PARSED %d NUMBERS ===\n", stack->size);
	current = stack->top;
	while (current)
	{
		ft_printf(1, "%d\n", current->content);
		current = current->next;
	}
	free_stack(stack);
	return (0);
}
