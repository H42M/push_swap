/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:40:33 by epetrill          #+#    #+#             */
/*   Updated: 2025/12/08 13:03:14 by hgeorges         ###   ########.fr       */
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
void	ft_min_sort(t_stack *stack_a, t_stack *stack_b, t_ope *ope);

// algo_medium_utils.c
void	ft_find_min_max(t_list *stack, int *min, int *max);
int		is_in_range(int value, int min, int max);
int		find_in_range(t_list *stack, int min, int max);

// algo_medium.c
void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, t_ope *ope);

// algo_complex_index_mapping.c
void	index_mapping(t_stack *a);

// algo_complex.c
void	ft_radix_sort(t_stack *a, t_stack *b, t_ope *ope);

// algo_adaptive.c
void	ft_adaptive_sort(t_stack *a, t_stack *b, t_ope *ope, float disorder);

// strategy.c
void	execute_strategy(t_stack *a, t_stack *b, t_ope *ope, float disorder);

// benchmark.c
void	ft_print_benchmark(t_ope *ope, float disorder);

#endif