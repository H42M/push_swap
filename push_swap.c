/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:55:38 by hgeorges          #+#    #+#             */
/*   Updated: 2025/11/27 01:05:31 by hgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		lst_index;
	t_list	*temp;
	t_list	**list_ptr;

	if (argc < 2)
		return (error()); // renvoyer dans stderr
	*list_ptr = NULL;
	while (argv[lst_index])
	{
		ft_lstadd_back(list_ptr, ft_lstnew(ft_atoi(argv[lst_index])));
		lst_index++;
	}
}

/*Pensez aux whitespaces (exemples avec $ARG)*/