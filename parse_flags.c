/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:37:49 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/08 12:40:43 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"

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
