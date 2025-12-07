/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:56:29 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/03 07:46:16 by epetrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, int *count, int fd)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_print_str(char *s, int *count, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_print_str("(null)", count, fd);
		return ;
	}
	while (s[i])
	{
		ft_print_char(s[i], count, fd);
		i++;
	}
}

void	ft_print_nbr(long n, int *count, int fd)
{
	if (n < 0)
	{
		ft_print_char('-', count, fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_nbr(n / 10, count, fd);
	}
	ft_print_char(n % 10 + '0', count, fd);
}

void	ft_putnbr_base(unsigned long nbr, char c, int *count, int fd)
{
	char	*tab;

	tab = NULL;
	if (c == 'x')
		tab = "0123456789abcdef";
	else if (c == 'X')
		tab = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, c, count, fd);
	}
	ft_print_char(tab[nbr % 16], count, fd);
}

void	ft_print_float(double n, int *count, int fd)
{
	long	total;
	int		int_part;
	int		frac;

	total = (long)(n * 100);
	int_part = (int)(total / 100);
	frac = (int)(total % 100);
	if (int_part < 10)
	{
		ft_print_char('0', count, fd);
		ft_print_char('0' + int_part, count, fd);
	}
	else
		ft_print_nbr((long)int_part, count, fd);
	ft_print_char('.', count, fd);
	if (frac < 10)
	{
		ft_print_char('0', count, fd);
		ft_print_char('0' + frac, count, fd);
	}
	else
		ft_print_nbr((long)frac, count, fd);
}
