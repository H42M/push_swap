/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:15:24 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 15:12:50 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <limits.h>
# include "push_swap.h"

// parse_flags.c
void	flag_check(char *av, t_ope *t_ope);

// parser.c
t_list	*parse_input(int ac, char **av, t_ope *s_ope);

// parser_utils.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atol(const char *nptr);

#endif