/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:45:01 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/16 17:15:16 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

t_stack	create_new_chunk(t_stack dst)
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
