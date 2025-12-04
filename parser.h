/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:15:24 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 18:27:38 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <limits.h>
# include "push_swap.h"

// parse_flags.c
void	flag_check(char *av, t_ope *t_ope);
void	init_ope(t_ope *ope);
void	init_flags(t_ope *s_ope);

// parser.c
t_stack	*parse_input(int ac, char **av, t_ope *s_ope);

// parser_utils.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atol(const char *nptr);

#endif