/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:53:26 by epetrill          #+#    #+#             */
/*   Updated: 2025/11/27 03:50:26 by epetrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int		tmp;
	t_list	*maillon;

	tmp = (*stack)->content;
	maillon = (*stack)->next;
	(*stack)->content = maillon->content;
	maillon->content = tmp;
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = NULL;
	ft_lstadd_back(&tmp, *stack);
	*stack = tmp;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*previous;

	tmp = ft_lstlast(*stack);
	previous = *stack;
	while (previous->next != tmp)
		previous = previous->next;
	previous->next = NULL;
	ft_lstadd_front(stack, tmp);
}
