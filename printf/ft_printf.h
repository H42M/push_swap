/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:14:05 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 13:46:37 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// ft_printf.c
int		ft_printf(int fd, const char *str, ...);
void	parse_format(va_list args, char c, int *count, int fd);
void	parse_format2(va_list args, char c, int *count, int fd);
// ft_printf_utils.c
void	ft_print_char(char c, int *count, int fd);
void	ft_print_str(char *s, int *count, int fd);
void	ft_print_nbr(long n, int *count, int fd);
void	ft_putnbr_base(unsigned long nbr, char c, int *count, int fd);
void	ft_print_float(double n, int *count, int fd);

#endif