/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:40:33 by epetrill          #+#    #+#             */
/*   Updated: 2025/12/03 09:05:01 by epetrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "push_swap.h"

// algo_utils.c
int		lst_is_sorted(t_list *stack);
float	calculate_disorder(t_list *stack);
int		ft_isqrt(int n);


// algo_simple.c
void	ft_min_sort(t_stack *stack_a, t_stack *stack_b);

// algo_medium.c
void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b);

// algo_complex.c
void	ft_complex_sort(t_stack *a, t_stack *b, t_ope *ope);

// algo_adaptive.c
void	ft_adaptive_sort(t_stack *a, t_stack *b, t_ope *ope);

// strategy.c
void	execute_strategy(t_stack *a, t_stack *b, t_ope *ope);

// benchmark.c
void	print_benchmark(t_ope *ope, float disorder, char *strategy);

#endif