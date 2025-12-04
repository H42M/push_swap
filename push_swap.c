/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:55:38 by hgeorges          #+#    #+#             */
/*   Updated: 2025/12/04 14:48:08 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"

int	main(int argc, char **argv)
{
	t_list	*list_ptr;

	if (argc < 2)
		return (0);
	list_ptr = NULL;
	list_ptr = parse_input(argc, argv);
}
