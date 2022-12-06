/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:37:42 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/06 18:20:51 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

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
}

t_stack	create_stack_a(char **argv, int argc)
{
	t_stack	stack_a;

	stack_a.max_length = argc - 1;
	stack_a.length = stack_a.max_length;
	stack_a.stack = ft_calloc(stack_a.max_length, sizeof(int));
	stack_a.location = 'a';
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
	return (stack_b);
}
