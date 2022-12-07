/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:37:42 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/07 16:58:03 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

static void	populate_chunks(t_chunks *chunks, int length)
{
	chunks->chunks[0] = length;
}

static void	populate_stack(t_stack *stack, char **argv)
{
	int	i;
	int	j;

	i = stack->length - 1;
	j = 1;
	while (i >= 0)
	{
		stack->stack[i] = ft_atoi(argv[j]);
		i--;
		j++;
	}
	populate_chunks(&stack->chunks, stack->length);
}

t_stack	create_stack_a(char **argv, int argc)
{
	t_stack	stack_a;

	stack_a.max_length = argc - 1;
	stack_a.length = stack_a.max_length;
	stack_a.stack = ft_calloc(stack_a.max_length, sizeof(int));
	stack_a.location = 'a';
	stack_a.chunks.max_length = stack_a.max_length;
	stack_a.chunks.chunks = ft_calloc(stack_a.chunks.max_length, sizeof(int));
	stack_a.chunks.length = 1;
	populate_stack(&stack_a, argv);
	return (stack_a);
}

t_stack	create_stack_b(int max_length)
{
	t_stack	stack_b;

	stack_b.max_length = max_length;
	stack_b.length = 0;
	stack_b.stack = ft_calloc(max_length, sizeof(int));
	stack_b.location = 'b';
	stack_b.chunks.max_length = stack_b.max_length;
	stack_b.chunks.chunks = ft_calloc(stack_b.chunks.max_length, sizeof(int));
	stack_b.chunks.length = 0;
	// populate_chunks(&stack_b.chunks, 0);
	return (stack_b);
}
