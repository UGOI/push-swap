/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:09:56 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/11 13:35:46 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

int	get_median(t_stack stack)
{
	int	res;
	int	stack_index;
	int	top_chunk;
	int	halfed_top_chunk;

	top_chunk = stack.chunks.chunks[stack.chunks.length - 1];
	if (top_chunk == 1)
		halfed_top_chunk = 0;
	else
		halfed_top_chunk = top_chunk / (int)2;
	stack_index = stack.length - halfed_top_chunk - 1;
	res = stack.stack[stack_index];
	return (res);
}

int	has_num_to_push(t_stack stack, int num)
{
	int	i;

	if (stack.length > 0)
	{
		i = stack.length - stack.chunks.chunks[stack.chunks.length - 1];
		while (i < stack.length)
		{
			if (stack.stack[i] <= num && stack.location == 'a')
				return (1);
			else if (stack.stack[i] >= num && stack.location == 'b')
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
	if (src->location == 'a')
	{
		while (src->stack[src->length - 1] > num)
		{
			*src = rotate(*src);
			i++;
		}
	}
	else if (src->location == 'b')
	{
		while (src->stack[src->length - 1] < num)
		{
			*src = rotate(*src);
			i++;
		}
	}
	return (i);
}

int	push_chunk(t_stack *src, t_stack *dst)
{
	int	rotations;
	int	num;

	num = get_median(*src);
	if (has_num_to_push(*src, num))
	{
		*dst = create_new_chunk(*dst);
		rotations = 0;
		while (has_num_to_push(*src, num))
		{
			rotations += rotate_till_can_push(src, num);
			if (src->stack[src->length - 1] <= num && src->location == 'a')
				push(src, dst);
			else if (src->stack[src->length - 1] >= num && src->location == 'b')
				push(src, dst);
		}
		rotate_to_orig(src, rotations);
		num = get_median(*src);
	}
	if (has_num_to_push(*src, num))
		return (0);
	return (1);
}

void	push_all(t_stack *src, t_stack *dst)
{
	int	pushed_everything;

	pushed_everything = push_chunk(src, dst);
	while (!pushed_everything)
	{
		pushed_everything = push_chunk(src, dst);
	}
}

int	is_stack_a_sorted_desc(t_stack stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a.length - 1)
	{
		if (stack_a.stack[i] < stack_a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_stack sort_small_stack_desc(t_stack stack_a)
{
	t_stack stack_b;

	stack_b = create_stack_b(stack_a.max_length);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
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
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	free(stack_b.stack);
	free(stack_b.chunks.chunks);
	return (stack_a);
}

t_stack	sort_big_stack(t_stack stack_a)
{
	t_stack	stack_b;

	stack_b = create_stack_b(stack_a.max_length);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	ft_printf("\n");
	while (!is_stack_a_sorted_desc(stack_a))
	{
		push_all(&stack_a, &stack_b);
		push_all(&stack_b, &stack_a);
	}
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
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
