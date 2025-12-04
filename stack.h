/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 13:30:00 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

// stack_init.c
t_list	*init_list(char **tab);
int		duplicates_check(t_list *stack);

// stack_utils.c
t_stack	*init_stack(char **tab);

// error.c
void	free_stack(t_stack *stack);
void	error_handler(void);

#endif
