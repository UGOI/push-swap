/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:40:07 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/15 20:14:29 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_chunks(t_chunks chunks, char message)
{
	int	i;

	ft_printf("CHUNKS_%c:	", message);
	i = chunks.length - 1;
	while (i >= 0)
	{
		ft_printf("%d ", chunks.chunks[i]);
		i--;
	}
	ft_printf("\n");
}

void	print_stack(t_stack stack, char message)
{
	int	i;

	ft_printf("STACK_%c:	", message);
	i = stack.length - 1;
	while (i >= 0)
	{
		ft_printf("%d ", stack.stack[i]);
		i--;
	}
	ft_printf("\n");
	print_chunks(stack.chunks, message);
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	char	**converted_input;

	if (argc == 1)
	{
		return (0);
	}
	converted_input = convert_input(argc, argv);
	if (converted_input == NULL)
		return (1);
	check_input(converted_input);
	stack_a = create_stack_a(argv, argc);
	stack_a = sort_stack(stack_a);
	free(stack_a.stack);
	free(stack_a.chunks.chunks);
	ft_free_split(converted_input);
	return (0);
}
