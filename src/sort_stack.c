/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:09:56 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/15 17:32:28 by sdukic           ###   ########.fr       */
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
	sorted_chunk = malloc(sizeof(int) * stack.chunks.chunks[stack.chunks.length - 1]);
	if (sorted_chunk == NULL)
		return (0);
	ft_memcpy(sorted_chunk, stack.stack + stack.length - stack.chunks.chunks[stack.chunks.length - 1], sizeof(int) * stack.chunks.chunks[stack.chunks.length - 1]);
	ft_sort_int_tab(sorted_chunk, stack.chunks.chunks[stack.chunks.length - 1]);
	median = sorted_chunk[stack.chunks.chunks[stack.chunks.length - 1] / 2];
	free(sorted_chunk);
	return (median);
}

int	has_num_to_push(t_stack stack, int num)
{
	int	i;

	if (stack.length > 0)
	{
		i = stack.length - stack.chunks.chunks[stack.chunks.length - 1];
		if (stack.chunks.chunks[stack.chunks.length - 1] == 1)
			return (1);
		while (i < stack.length)
		{
			if (stack.stack[i] < num && stack.location == 'a')
				return (1);
			else if (stack.stack[i] > num && stack.location == 'b')
				return (1);
			i++;
		}
	}
	return (0);
}

void	rotate_to_orig(t_stack *src, int i)
{
	if (src->chunks.length > 1)
		while (i--)
			*src = rrotate(*src);
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


t_stack create_new_chunk(t_stack dst)
{
	dst.chunks.length++;
	dst.chunks.chunks[dst.chunks.length - 1] = 0;
	return (dst);
}

int	rotate_till_can_push(t_stack *src, int num)
{
	int	i;

	i = 0;
	if (src->chunks.chunks[src->chunks.length - 1] == 1)
		return (0);
	if (src->location == 'a')
	{
		while (src->stack[src->length - 1] >= num)
		{
			*src = rotate(*src);
			i++;
		}
	}
	else if (src->location == 'b')
	{
		while (src->stack[src->length - 1] <= num)
		{
			*src = rotate(*src);
			i++;
		}
	}
	return (i);
}

void	rotate_back(t_stack *src, int i)
{
	while (i--)
		*src = rrotate(*src);
}

t_stack sort_duo_chunk(t_stack stack)
{
	int	top_num;
	int	bot_num;

	if (stack.chunks.chunks[stack.chunks.length - 1] == 2)
	{
		top_num = stack.stack[stack.length - 1];
		bot_num = stack.stack[stack.length - 2];
		if (top_num > bot_num && stack.location == 'a')
			stack = swap(stack);
		else if (top_num < bot_num && stack.location == 'b')
			stack = swap(stack);
	}
	return (stack);
}

t_stack sort_small_stack_desc(t_stack stack_a)
{
	if (stack_a.length == 2)
	{
		if (stack_a.stack[0] < stack_a.stack[1])
			stack_a = swap(stack_a);
	}
	else if (stack_a.length == 3)
	{
		if (stack_a.stack[2] > stack_a.stack[1]
			&& stack_a.stack[2] > stack_a.stack[0])
			stack_a = rotate(stack_a);
		else if (stack_a.stack[1] > stack_a.stack[0])
			stack_a = rrotate(stack_a);
		if (stack_a.stack[1] < stack_a.stack[2])
			stack_a = swap(stack_a);
	}
	return (stack_a);
}


int		get_amount_of_numbers_for_next_chunk(t_stack stack, int median)
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

void	push_chunk(t_stack *src, t_stack *dst)
{
	int	amount_of_numbers_for_next_chunk;
	int	median;
	int rotations;

	rotations = 0;
	median = get_median(*src);
	amount_of_numbers_for_next_chunk = get_amount_of_numbers_for_next_chunk(*src, median);
	if (src->chunks.chunks[src->chunks.length - 1] == 2)
	{
		*src = sort_duo_chunk(*src);
		if (!is_stack_sorted(*src))
		{
			*dst = create_new_chunk(*dst);
			push(src, dst);
			push(src, dst);
		}
		return ;
	}
	if (amount_of_numbers_for_next_chunk != 0 && src->chunks.chunks[src->chunks.length - 1] != 2)
		*dst = create_new_chunk(*dst);
	while (amount_of_numbers_for_next_chunk > 0 && src->chunks.chunks[src->chunks.length - 1] != 2)
	{
		if (src->stack[0] < median && src->location == 'a')
		{
			*src = rrotate(*src);
			push(src, dst);
			amount_of_numbers_for_next_chunk--;
		}
		else if (src->stack[0] > median && src->location == 'b')
		{
			*src = rrotate(*src);
			push(src, dst);
			amount_of_numbers_for_next_chunk--;
		}
		else
		{

			rotations += rotate_till_can_push(src, median);
			push(src, dst);
			amount_of_numbers_for_next_chunk--;
		}
	}
	if (src->chunks.length > 1)
		rotate_back(src, rotations);
	return ;
}

void	push_stack(t_stack *src, t_stack *dst)
{
	while (!is_stack_sorted(*src))
	{
		push_chunk(src, dst);
		// printf("\n");
	}
	if (dst->location == 'a' && is_stack_sorted(*src) && is_stack_sorted(*dst))
	{
		while (src->length > 0)
			push(src, dst);
	}
}

t_stack	sort_big_stack(t_stack stack_a)
{
	t_stack	stack_b;

	stack_b = create_stack_b(stack_a.max_length);
	while (!is_stack_sorted(stack_a))
	{
		push_stack(&stack_a, &stack_b);
		// print_stack(stack_a, 'A');
		// print_stack(stack_b, 'B');
		push_stack(&stack_b, &stack_a);
		// print_stack(stack_a, 'A');
		// print_stack(stack_b, 'B');
	}
	// print_stack(stack_b, 'B');
	free(stack_b.stack);
	free(stack_b.chunks.chunks);
	return (stack_a);
}


t_stack	sort_stack(t_stack stack_a)
{
	if (stack_a.length <= 3)
		return (sort_small_stack_desc(stack_a));
	else
		return (sort_big_stack(stack_a));
}
