/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:14:05 by hgeorges          #+#    #+#             */
/*   Updated: 2025/11/26 02:16:07 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "push_swap.h"

// ft_printf.c
int		ft_printf(const char *str, ...);
void	parse_format(va_list args, char c, int *count);
void	parse_format2(va_list args, char c, int *count);
// ft_printf_utils.c
void	ft_print_char(char c, int *count);
void	ft_print_str(char *s, int *count);
void	ft_print_nbr(long n, int *count);
void	ft_putnbr_base(unsigned long nbr, char c, int *count);

#endif