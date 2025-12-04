/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:37:49 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/02 18:30:10 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_flags(t_ope *s_ope)
{
	s_ope->simple = 0;
	s_ope->medium = 0;
	s_ope->complex = 0;
	s_ope->adaptive = 0;
	s_ope->bench = 0;
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

void	flag_check(int ac, char *av, t_ope *s_ope)
{
	int	i;

	i = 1;
	init_flags(s_ope);
	process_flags(av, s_ope);
	if (s_ope->adaptive + s_ope->simple + s_ope->medium + s_ope->complex > 1)
		error_handler();
}
