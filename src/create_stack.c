/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:37:42 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/16 17:10:50 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

t_stack	create_basic_stack(int max_length)
{
	t_stack	stack;

	stack.max_length = max_length;
	stack.stack = ft_calloc(stack.max_length, sizeof(int));
	stack.chunks.max_length = stack.max_length;
	stack.chunks.chunks = ft_calloc(stack.chunks.max_length, sizeof(int));
	return (stack);
}

t_stack	create_stack_a(char **argv, int argc)
{
	t_stack	stack_a;
	int		max_length;

	max_length = get_max_stack_length(argv, argc);
	stack_a = create_basic_stack(max_length);
	stack_a.chunks.length = 1;
	stack_a.length = stack_a.max_length;
	stack_a.location = 'a';
	populate_stack(&stack_a, argv, argc);
	return (stack_a);
}

t_stack	create_stack_b(int max_length)
{
	t_stack	stack_b;

	stack_b = create_basic_stack(max_length);
	stack_b.chunks.length = 0;
	stack_b.length = 0;
	stack_b.location = 'b';
	return (stack_b);
}
