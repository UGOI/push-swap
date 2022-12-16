/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:56:08 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/16 15:22:57 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

void	push_duo_chunk(t_stack *src, t_stack *dst)
{
	*src = sort_duo_chunk(*src);
	if (!is_stack_sorted(*src))
	{
		*dst = create_new_chunk(*dst);
		push(src, dst);
		push(src, dst);
	}
}

int	rotate_and_push(t_stack *src, t_stack *dst, int median)
{
	int	rotations;

	rotations = 0;
	if (src->stack[0] < median && src->location == 'a')
	{
		*src = rrotate(*src);
		push(src, dst);
	}
	else if (src->stack[0] > median && src->location == 'b')
	{
		*src = rrotate(*src);
		push(src, dst);
	}
	else
	{
		rotations += rotate_till_can_push(src, median);
		push(src, dst);
	}
	return (rotations);
}

void	push_efficiently(t_stack *src, t_stack *dst, int median)
{
	int	rotations;
	int	amount_of_numbers_for_next_chunk;

	amount_of_numbers_for_next_chunk
		= get_amount_of_numbers_for_next_chunk(*src, median);
	rotations = 0;
	while (amount_of_numbers_for_next_chunk > 0
		&& src->chunks.chunks[src->chunks.length - 1] != 2)
	{
		rotations += rotate_and_push(src, dst, median);
		amount_of_numbers_for_next_chunk--;
	}
	if (src->chunks.length > 1)
		rotate_back(src, rotations);
}

void	push_chunk(t_stack *src, t_stack *dst)
{
	int	amount_of_numbers_for_next_chunk;
	int	median;

	median = get_median(*src);
	amount_of_numbers_for_next_chunk
		= get_amount_of_numbers_for_next_chunk(*src, median);
	if (src->chunks.chunks[src->chunks.length - 1] == 2)
	{
		push_duo_chunk(src, dst);
		return ;
	}
	if (amount_of_numbers_for_next_chunk != 0
		&& src->chunks.chunks[src->chunks.length - 1] != 2)
		*dst = create_new_chunk(*dst);
	push_efficiently(src, dst, median);
	return ;
}
