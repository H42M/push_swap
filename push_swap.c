/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:55:38 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 15:19:36 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "printf/ft_printf.h"

int	main(int argc, char **argv)
{
	t_list	*list_ptr;
	t_ope	*s_ope;

	s_ope = NULL;
	if (argc < 2)
		return (0);
	list_ptr = NULL;
	list_ptr = parse_input(argc, argv, s_ope);
	while (list_ptr)
	{
		ft_printf(1, "%d\n", list_ptr->content);
		list_ptr = list_ptr->next;
	}
}
