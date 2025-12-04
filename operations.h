/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:00 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 13:30:00 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

// operations.c
void	swap(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope);
void	push(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope);
void	rotate(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope);
void	r_rotate(t_stack *stack_1, t_stack *stack_2, int flag, t_ope *ope);

#endif
