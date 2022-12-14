/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:40:07 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/14 20:21:54 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

void errprintf(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}


void ft_free_split(char **split)
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

int	is_argv_int(int argc, char *argv[])
{
	int	j;
	int i;

	j = 1;
	while (j < argc)
	{
		char	**split;

		split = ft_split(argv[j], ' ');
		if (split == NULL)
			return (0);
		i = 0;
		while (split[i])
		{
			if (is_str_digit(split[i]) == 0 || ft_latoi(split[i]) > INT_MAX || ft_latoi(split[i]) < INT_MIN)
			{
				ft_free_split(split);
				return (0);
			}
			i++;
		}

		// if (is_str_digit(argv[j]) == 0 || ft_latoi(argv[j]) > INT_MAX || ft_latoi(argv[j]) < INT_MIN)
		// {
		// 	return (0);
		// }
		j++;
		ft_free_split(split);
	}
	return (1);
}

void	check_input(int argc, char *argv[])
{
	if (is_argv_int(argc, argv) == 0 || argc == 1)
	{
		errprintf("Error\n");
		exit(1);
	}
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

	if (argc == 1)
	{
		return (0);
	}
	check_input(argc, argv);
	stack_a = create_stack_a(argv, argc);
	// print_stack(stack_a, 'A');
	stack_a = sort_stack(stack_a);
	// printf("median: %d\n" ,get_median(stack_a));
	// print_stack(stack_a, 'A');
	free(stack_a.stack);
	free(stack_a.chunks.chunks);
	return (0);
}
