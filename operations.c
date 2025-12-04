/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:53:26 by epetrill          #+#    #+#             */
/*   Updated: 2025/12/04 15:38:56 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "printf/ft_printf.h"

void	swap(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope)
{
	int		tmp;
	t_list	*maillon;

	if (stack_1->size < 2)
		return ;
	tmp = stack_1->top->content;
	maillon = stack_1->top->next;
	stack_1->top->content = maillon->content;
	maillon->content = tmp;
	if (flag == 0)
	{
		ft_printf(1, "sa\n");
		ope->count_sa++;
	}
	else if (flag == 1)
	{
		ft_printf(1, "sb\n");
		ope->count_sb++;
	}
	else if (flag == 2)
	{
		ft_printf(1, "ss\n");
		ope->count_ss++;
		swap(stack_2, stack_1, -1, ope);
	}
}

void	push(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope)
{
	t_list	*tmp;

	if (stack_1->size < 1)
		return ;
	tmp = stack_1->top->next;
	ft_lstadd_front(&stack_2->top, stack_1->top);
	stack_1->top = tmp;
	stack_1->size--;
	stack_2->size++;
	if (flag == 0)
	{
		ft_printf(1, "pa\n");
		ope->count_pa++;
	}
	else if (flag == 1)
	{
		ft_printf(1, "pb\n");
		ope->count_pb++;
	}
}

void	rotate(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope)
{
	t_list	*tmp;

	if (stack_1->size < 2)
		return ;
	tmp = stack_1->top->next;
	stack_1->top->next = NULL;
	ft_lstadd_back(&tmp, stack_1->top);
	stack_1->top = tmp;
	if (flag == 0)
	{
		ft_printf(1, "ra\n");
		ope->count_ra++;
	}
	else if (flag == 1)
	{
		ft_printf(1, "rb\n");
		ope->count_rb++;
	}
	else if (flag == 2)
	{
		ft_printf(1, "rr\n");
		ope->count_rr++;
		rotate(stack_2, stack_1, -1, ope);
	}
}

void	r_rotate(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope)
{
	t_list	*tmp;

	if (stack_1->size < 2)
		return ;
	tmp = ft_lstprevious(stack_1->top);
	ft_lstadd_front(&(stack_1->top), stack_1->bottom);
	tmp->next = NULL;
	stack_1->bottom = tmp;
	if (flag == 0)
	{
		ft_printf(1, "rra\n");
		ope->count_rra++;
	}
	else if (flag == 1)
	{
		ft_printf(1, "rrb\n");
		ope->count_rrb++;
	}
	else if (flag == 2)
	{
		ft_printf(1, "rrr\n");
		ope->count_rrr++;
		r_rotate(stack_2, stack_1, -1, ope);
	}
}
