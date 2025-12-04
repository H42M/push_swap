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
int		duplicates_check(t_list *stack);

// stack_utils.c
t_stack	*init_stack(t_list **numbers, int count);

// error.c
void	free_stack(t_stack *stack);
void	error_handler(void);

#endif
