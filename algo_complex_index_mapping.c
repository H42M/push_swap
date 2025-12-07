/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex_index_mapping.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:12:58 by Hugo              #+#    #+#             */
/*   Updated: 2025/12/07 22:39:04 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "algorithm.h"
#include "operations.h"
#include "list.h"
#include "stack.h"
#include "printf/ft_printf.h"

static int	*array_copying(t_stack *a)
{
	int		*arr;
	int		i;
	t_list	*current;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;
	current = a->top;
	while (current)
	{
		arr[i] = current->content;
		current = current->next;
		i++;
	}
	return (arr);
}

static void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_mapping(t_stack *a)
{
	int		i;
	int		*arr;
	t_list	*current;

	arr = array_copying(a);
	bubble_sort(arr, a->size);
	current = a->top;
	while (current)
	{
		i = 0;
		while (current->content != arr[i])
			i++;
		current->content = i;
		current = current->next;
	}
	free(arr);
}
