/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:15:24 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 13:09:32 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <limits.h>

// utils/ft_split.c
char	**ft_split(char const *s, char c);

// parse_flags.c
void	flag_check(int ac, char *av, t_ope *t_ope);

// parser.c
t_stack	*parse_input(int argc, char **argv);

// parser_utils.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atol(const char *nptr);

#endif