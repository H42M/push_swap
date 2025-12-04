/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:55:58 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 13:49:21 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "printf/ft_printf.h"
# include "parser.h"
# include "algorithm.h"
# include "operations.h"
# include "list.h"
# include "stack.h"

// utils/string_utils.c
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// utils/ft_split.c
char	**ft_split(char const *s, char c);

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	int		size;	
}	t_stack;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_ope
{
	int	count_sa;
	int	count_sb;
	int	count_ss;
	int	count_pa;
	int	count_pb;
	int	count_ra;
	int	count_rb;
	int	count_rr;
	int	count_rra;
	int	count_rrb;
	int	count_rrr;
	int	simple;
	int	complex;
	int	medium;
	int	adaptive;
	int	bench;
}	t_ope;

#endif