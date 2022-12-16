/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:08:29 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/16 17:08:44 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pushswap.h"
#include "./include/libft.h"
#include "./include/ft_printf.h"

t_stack	swap(t_stack stack)
{
	int	tmp;

	if (stack.length > 1)
	{
		tmp = stack.stack[stack.length - 2];
		stack.stack[stack.length - 2] = stack.stack[stack.length - 1];
		stack.stack[stack.length - 1] = tmp;
		ft_printf("s%c\n", stack.location);
	}
	else
		errprintf("Warning in _swap: can't swap because \
there are less than 2 elements in stack");
	return (stack);
}

void	push(t_stack *stack_src, t_stack *stack_dst)
{
	if (stack_src->length > 0 && stack_dst->length < stack_dst->max_length)
	{
		stack_dst->length++;
		stack_dst->stack[stack_dst->length - 1]
			= stack_src->stack[stack_src->length - 1];
		stack_src->length--;
		stack_dst->chunks.chunks[stack_dst->chunks.length - 1]++;
		stack_src->chunks.chunks[stack_src->chunks.length - 1]--;
		if (stack_src->chunks.chunks[stack_src->chunks.length - 1] == 0)
			stack_src->chunks.length--;
		ft_printf("p%c\n", stack_dst->location);
	}
	else if (stack_dst->length >= stack_dst->max_length)
	{
		errprintf("Warning in _push: stack alredy full");
	}
	else if (stack_src->length <= 0)
	{
		errprintf("Warning in _push: nothing to push");
	}
}

t_stack	rotate(t_stack stack)
{
	int	tmp;
	int	i;

	if (stack.length > 1)
	{
		i = stack.length - 1;
		tmp = stack.stack[i];
		while (i > 0)
		{
			stack.stack[i] = stack.stack[i - 1];
			i--;
		}
		stack.stack[0] = tmp;
		ft_printf("r%c\n", stack.location);
	}
	return (stack);
}

t_stack	rrotate(t_stack stack)
{
	int	tmp;
	int	i;

	if (stack.length > 1)
	{
		i = 0;
		tmp = stack.stack[i];
		while (i < stack.length - 1)
		{
			stack.stack[i] = stack.stack[i + 1];
			i++;
		}
		stack.stack[stack.length - 1] = tmp;
		ft_printf("rr%c\n", stack.location);
	}
	return (stack);
}
