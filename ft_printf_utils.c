/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:56:29 by hgeorges          #+#    #+#             */
/*   Updated: 2025/11/26 02:17:49 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_print_str(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_print_str("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_print_char(s[i], count);
		i++;
	}
}

void	ft_print_nbr(long n, int *count)
{
	if (n < 0)
	{
		ft_print_char('-', count);
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_nbr(n / 10, count);
	}
	ft_print_char(n % 10 + '0', count);
}

void	ft_putnbr_base(unsigned long nbr, char c, int *count)
{
	char	*tab;

	tab = NULL;
	if (c == 'x')
		tab = "0123456789abcdef";
	else if (c == 'X')
		tab = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, c, count);
	}
	ft_print_char(tab[nbr % 16], count);
}
