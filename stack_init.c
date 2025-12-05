/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:08:26 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 23:06:55 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

t_stack	*init_stack(t_list **numbers, int count)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = *numbers;
	stack->size = count;
	return (stack);
}

int	add_to_stack(t_list **numbers, char **tab)
{
	t_list	*new;
	int		i;
	long	val;

	i = 0;
	while (tab[i])
	{
		val = ft_atol(tab[i]);
		if (val < INT_MIN || val > INT_MAX)
			return (0);
		new = ft_lstnew((int)val);
		ft_lstadd_back(numbers, new);
		i++;
	}
	return (1);
}
