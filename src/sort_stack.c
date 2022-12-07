/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:09:56 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/07 21:22:09 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

int	get_median(t_stack stack)
{
	return (stack.stack[stack.length / (int)2]);
}

int	has_bigger_num(t_stack stack, int num)
{
	int	i;

	i = 0;
	while (i < stack.length)
		if (stack.stack[i++] > num)
			return (1);
	return (0);
}

int	has_smaller_num(t_stack stack, int num)
{
	int	i;

	i = 0;
	while (i < stack.length)
		if (stack.stack[i++] < num)
			return (1);
	return (0);
}

void	push_all_bigger(t_stack *src, t_stack *dst, int num)
{
	while (has_bigger_num(*src, num))
	{
		push(src, dst);
	}
}

void	rotate_to_orig(t_stack *src, int i)
{
	if (src->chunks.length > 1)
		while (i--)
			*src = rrotate(*src);
}

int	push_all_smaller(t_stack *src, t_stack *dst)
{
	int	i;
	int	num;

	num = get_median(*src);
	if (has_smaller_num(*src, num))
	{
		dst->chunks.length++;
		dst->chunks.chunks[dst->chunks.length - 1] = 0;
		i = 0;
		while (has_smaller_num(*src, num))
		{
			if (src->stack[src->length - 1] < num)
				push(src, dst);
			if (has_smaller_num(*src, num))
			{
				*src = rotate(*src);
				i++;
			}
		}
		rotate_to_orig(src, i);
		num = get_median(*src);
	}
	else
		return (0);
	return (1);
}

void	push_all_to_other_stack(t_stack *src, t_stack *dst)
{
	int	pushed_everything;

	pushed_everything = push_all_smaller(src, dst);
	while (pushed_everything)
	{
		pushed_everything = push_all_smaller(src, dst);
	}
}

t_stack	sort_stack_a(t_stack stack_a)
{
	t_stack	stack_b;

	stack_b = create_stack_b(stack_a.max_length);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	ft_printf("\n");
	push_all_to_other_stack(&stack_a, &stack_b);

	// median = get_median(stack_a);
	// push_all_to_other_stack(&stack_a, &stack_b);

	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	free(stack_b.stack);
	free(stack_b.chunks.chunks);
	return (stack_a);
}
