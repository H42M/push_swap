/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:08:26 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/03 10:39:01 by epetrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(char **tab)
{
	t_list	*stack;
	int		i;
	int		nbr;

	i = 0;
	while (tab[i])
	{
		nbr = ft_atol(tab[i]);
		ft_lstadd_back(&stack, ft_lstnew(nbr));
		i++;
	}
	return (stack);
}

int	duplicates_check(t_list *stack)
{
	t_list	*current;
	t_list	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return (-1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}
