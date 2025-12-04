/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:14:01 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 13:38:31 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(va_list args, char c, int *count, int fd)
{
	unsigned long	nbr;

	if (c == 'c')
		ft_print_char((char)va_arg(args, int), count, fd);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), count, fd);
	else if (c == 'p')
	{
		nbr = (unsigned long)va_arg(args, void *);
		if (nbr == 0)
			ft_print_str("(nil)", count, fd);
		else
		{
			ft_print_str("0x", count, fd);
			ft_putnbr_base(nbr, 'x', count, fd);
		}
	}
	parse_format2(args, c, count, fd);
}

void	parse_format2(va_list args, char c, int *count, int fd)
{
	unsigned long	nbr;

	if (c == 'd' || c == 'i')
		ft_print_nbr((long)va_arg(args, int), count, fd);
	else if (c == 'u')
		ft_print_nbr(va_arg(args, unsigned int), count, fd);
	else if (c == 'x' || c == 'X')
	{
		nbr = (unsigned long)va_arg(args, unsigned int);
		ft_putnbr_base(nbr, c, count, fd);
	}
	else if (c == '%')
		ft_print_char('%', count, fd);
	else if (c == 'f')
		ft_print_float((double)va_arg(args, double), count, fd);
}

int	ft_printf(const char *str, int fd, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_print_char(str[i], &count, fd);
		if (str[i] == '%')
		{
			parse_format(args, str[++i], &count, fd);
		}
		i++;
	}
	va_end(args);
	return (count);
}
