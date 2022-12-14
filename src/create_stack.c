/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:37:42 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/14 20:46:41 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

static void	populate_chunks(t_chunks *chunks, int length)
{
	if (chunks->max_length == 0)
		return ;
	chunks->chunks[0] = length;
}

// static void	populate_stack(t_stack *stack, char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = stack->length - 1;
// 	j = 1;
// 	while (i >= 0)
// 	{
// 		stack->stack[i] = ft_atoi(argv[j]);
// 		i--;
// 		j++;
// 	}
// 	populate_chunks(&stack->chunks, stack->length);
// }

static void	populate_stack(t_stack *stack, char **argv, int argc)
{
	int	j;
	int i;
	char	**split;
	int	stack_i;

	stack_i = stack->length - 1;
	j = 1;
	while (j < argc)
	{
		split = ft_split(argv[j], ' ');
		if (split == NULL)
			return ;
		i = 0;
		while (split[i])
		{
			stack->stack[stack_i] = ft_atoi(split[i]);
			i++;
			stack_i--;
		}
		j++;
		ft_free_split(split);
	}
	populate_chunks(&stack->chunks, stack->length);
}

t_stack	create_basic_stack(int max_length)
{
	t_stack	stack;

	stack.max_length = max_length;
	stack.stack = ft_calloc(stack.max_length, sizeof(int));
	stack.chunks.max_length = stack.max_length;
	stack.chunks.chunks = ft_calloc(stack.chunks.max_length, sizeof(int));
	return (stack);
}

// t_stack	create_stack_a(char **argv, int max_length)
// {
// 	t_stack	stack_a;

// 	stack_a = create_basic_stack(max_length);
// 	stack_a.chunks.length = 1;
// 	stack_a.length = stack_a.max_length;
// 	stack_a.location = 'a';
// 	populate_stack(&stack_a, argv);
// 	return (stack_a);
// }

int	get_max_stack_length(char **argv, int argc)
{
	int	j;
	int i;
	int	max_length;
	char	**split;

	max_length = 0;
	j = 1;
	while (j < argc)
	{
		split = ft_split(argv[j], ' ');
		if (split == NULL)
			return (0);
		i = 0;
		while (split[i])
		{
			max_length++;
			i++;
		}
		j++;
		ft_free_split(split);
	}
	return (max_length);
}

t_stack	create_stack_a(char **argv, int argc)
{
	t_stack	stack_a;
	int	max_length;

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
