/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:55:38 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/08 14:37:26 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "printf/ft_printf.h"

/* void	ft_print_stack(t_stack *stack, int flag)
{
	t_list	*tmp;

	tmp = stack->top;
	if (flag)
		ft_printf(1, "Stack a contents:\n");
	else
		ft_printf(1, "Stack b contents:\n");
	while (tmp)
	{
		ft_printf(1, "%d\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf(1, "size = %d", stack->size);
	ft_printf(1, "\n");
} */

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_ope	ope;
	t_list	*list;
	float	disorder;

	init_ope(&ope);
	list = parse_input(argc, argv, &ope);
	stack_a = init_stack(list, ft_lstsize(list));
	stack_b = init_stack(NULL, 0);
	disorder = calculate_disorder(stack_a->top);
	if (lst_is_sorted(list))
	{
		if (ope.bench)
			ft_print_benchmark(&ope, disorder);
		return (free_stack(stack_a), free_stack(stack_b), 0);
	}
	execute_strategy(stack_a, stack_b, &ope, disorder);
	if (ope.bench)
		ft_print_benchmark(&ope, disorder);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
