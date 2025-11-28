/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:14:01 by hgeorges          #+#    #+#             */
/*   Updated: 2025/11/26 01:32:46 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(va_list args, char c, int *count)
{
	unsigned long	nbr;

	if (c == 'c')
		ft_print_char((char)va_arg(args, int), count);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (c == 'p')
	{
		nbr = (unsigned long)va_arg(args, void *);
		if (nbr == 0)
			ft_print_str("(nil)", count);
		else
		{
			ft_print_str("0x", count);
			ft_putnbr_base(nbr, 'x', count);
		}
	}
	parse_format2(args, c, count);
}

void	parse_format2(va_list args, char c, int *count)
{
	unsigned long	nbr;

	if (c == 'd' || c == 'i')
		ft_print_nbr((long)va_arg(args, int), count);
	else if (c == 'u')
		ft_print_nbr(va_arg(args, unsigned int), count);
	else if (c == 'x' || c == 'X')
	{
		nbr = (unsigned long)va_arg(args, unsigned int);
		ft_putnbr_base(nbr, c, count);
	}
	else if (c == '%')
		ft_print_char('%', count);
}

int	ft_printf(const char *str, ...)
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
			ft_print_char(str[i], &count);
		if (str[i] == '%')
		{
			parse_format(args, str[++i], &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}
