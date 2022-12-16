/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:09:56 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/16 17:15:40 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

void	push_stack(t_stack *src, t_stack *dst)
{
	while (!is_stack_sorted(*src))
	{
		push_chunk(src, dst);
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
		push_stack(&stack_b, &stack_a);
	}
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
