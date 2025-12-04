/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:00:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 15:09:12 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

/*
** Stack Utilities - Helper functions for t_stack operations
** init_stack() - Creates t_stack wrapper from t_list
** update_stack_bottom() - Updates bottom pointer after operations
** Additional stack-specific helpers as needed
*/

t_stack	*init_stack(char **tab)
{
	t_stack	*stack;
	t_list	*list;

	list = init_list(tab);
	if (!list)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = list;
	stack->bottom = ft_lstlast(list);
	stack->size = ft_lstsize(list);
	return (stack);
}
