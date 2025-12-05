/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 18:45:46 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

// stack_init.c
t_stack	*init_stack(t_list **numbers, int count);
int		add_to_stack(t_list **numbers, char **tab);

// stack_utils.c
int		duplicates_check(t_list *stack);

// error.c
void	free_stack(t_stack *stack);
void	error_handler(void);

#endif
