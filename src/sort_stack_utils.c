/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:17:13 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/15 21:51:43 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

int	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_median(t_stack stack)
{
	int	median;
	int	*sorted_chunk;

	if (stack.length == 0)
		return (0);
	sorted_chunk = malloc(sizeof(int)
			* stack.chunks.chunks[stack.chunks.length - 1]);
	if (sorted_chunk == NULL)
		return (0);
	ft_memcpy(sorted_chunk, stack.stack + stack.length
		- stack.chunks.chunks[stack.chunks.length - 1],
		sizeof(int) * stack.chunks.chunks[stack.chunks.length - 1]);
	ft_sort_int_tab(sorted_chunk, stack.chunks.chunks[stack.chunks.length - 1]);
	median = sorted_chunk[stack.chunks.chunks[stack.chunks.length - 1] / 2];
	free(sorted_chunk);
	return (median);
}

int	is_stack_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.length - 1)
	{
		if (stack.stack[i] > stack.stack[i + 1] && stack.location == 'b')
			return (0);
		else if (stack.stack[i] < stack.stack[i + 1] && stack.location == 'a')
			return (0);
		i++;
	}
	return (1);
}

int	get_amount_of_numbers_for_next_chunk(t_stack stack, int median)
{
	int	i;
	int	amount_of_numbers_for_next_chunk;

	amount_of_numbers_for_next_chunk = 0;
	if (stack.length > 0)
	{
		i = stack.length - stack.chunks.chunks[stack.chunks.length - 1];
		if (stack.chunks.chunks[stack.chunks.length - 1] == 1)
			return (1);
		while (i < stack.length)
		{
			if (stack.stack[i] < median && stack.location == 'a')
				amount_of_numbers_for_next_chunk++;
			else if (stack.stack[i] > median && stack.location == 'b')
				amount_of_numbers_for_next_chunk++;
			i++;
		}
	}
	return (amount_of_numbers_for_next_chunk);
}
