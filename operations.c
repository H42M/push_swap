/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:53:26 by epetrill          #+#    #+#             */
/*   Updated: 2025/12/03 08:55:07 by epetrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_printf("sa\n", 1);
		ope->count_sa++;
	}
	else if (flag == 1)
	{
		ft_printf("sb\n", 1);
		ope->count_sb++;
	}
	else if (flag == 2)
	{
		ft_printf("ss\n", 1);
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
		ft_printf("pa\n", 1);
		ope->count_pa++;
	}
	else if (flag == 1)
	{
		ft_printf("pb\n", 1);
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
		ft_printf("ra\n", 1);
		ope->count_ra++;
	}
	else if (flag == 1)
	{
		ft_printf("rb\n", 1);
		ope->count_rb++;
	}
	else if (flag == 2)
	{
		ft_printf("rr\n", 1);
		ope->count_rr++;
		rotate(stack_2, stack_1, -1, ope);
	}
}

void	r_rotate(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope)
{
	t_list	*tmp;
	t_list	*previous;

	if (stack_1->size < 2)
		return ;
	tmp = ft_lstprevious(stack_1->top);
	ft_lstadd_front(&(stack_1->top), stack_1->bottom);
	tmp->next = NULL;
	stack_1->bottom = tmp;
	if (flag == 0)
	{
		ft_printf("rra\n", 1);
		ope->count_rra++;
	}
	else if (flag == 1)
	{
		ft_printf("rrb\n", 1);
		ope->count_rrb++;
	}
	else if (flag == 2)
	{
		ft_printf("rrr\n", 1);
		ope->count_rrr++;
		r_rotate(stack_2, stack_1, -1, ope);
	}
}
