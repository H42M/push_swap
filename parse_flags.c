/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:37:49 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 23:57:12 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

t_ope *init_ope(void)
{
	t_ope	*ope;
	
    ope = malloc(sizeof(t_ope));
	if (!ope)
		return (NULL);
	ope->count_sa = 0;
	ope->count_sb = 0;
	ope->count_ss = 0;
	ope->count_pa = 0;
	ope->count_pb = 0;
	ope->count_ra = 0;
	ope->count_rb = 0;
	ope->count_rr = 0;
	ope->count_rra = 0;
	ope->count_rrb = 0;
	ope->count_rrr = 0;
	ope->simple = 0;
	ope->complex = 0;
	ope->medium = 0;
	ope->adaptive = 0;
	ope->bench = 0;
	return (ope);
}

static void	process_flags(char *av, t_ope *s_ope)
{
	if (ft_strcmp(av, "--simple") == 0)
		s_ope->simple = 1;
	else if (ft_strcmp(av, "--medium") == 0)
		s_ope->medium = 1;
	else if (ft_strcmp(av, "--complex") == 0)
		s_ope->complex = 1;
	else if (ft_strcmp(av, "--adaptive") == 0)
		s_ope->adaptive = 1;
	else if (ft_strcmp(av, "--bench") == 0)
		s_ope->bench = 1;
	else
		error_handler();
}

void	flag_check(char *av, t_ope *s_ope)
{
	process_flags(av, s_ope);
}
