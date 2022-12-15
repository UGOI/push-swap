/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:01:23 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/15 23:48:55 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

t_stack	sort_duo_chunk(t_stack stack)
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

t_stack	sort_small_stack_desc(t_stack stack_a)
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
