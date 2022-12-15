/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:09:07 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/15 20:12:16 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

void	populate_chunk(t_chunks *chunks, int length)
{
	if (chunks->max_length == 0)
		return ;
	chunks->chunks[0] = length;
}

void	populate_stack(t_stack *stack, char **argv, int argc)
{
	int		j;
	int		i;
	char	**split;
	int		stack_i;

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
	populate_chunk(&stack->chunks, stack->length);
}

int	get_max_stack_length(char **argv, int argc)
{
	int		j;
	int		i;
	int		max_length;
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
