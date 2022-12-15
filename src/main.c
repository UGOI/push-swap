/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:40:07 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/15 14:44:45 by sdukic           ###   ########.fr       */
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

int	is_converted_int(char **converted_input)
{
	int	i;

	i = 0;
	while (converted_input[i])
	{
		if (is_str_digit(converted_input[i]) == 0 || ft_latoi(converted_input[i]) > INT_MAX || ft_latoi(converted_input[i]) < INT_MIN)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	has_duplicates(char **convert_input)
{
	int	i;
	int	j;

	i = 0;
	while (convert_input[i])
	{
		j = i + 1;
		while (convert_input[j])
		{
			if (ft_latoi(convert_input[i]) == ft_latoi(convert_input[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_input(char **converted_input)
{
	if (is_converted_int(converted_input) == 0 || has_duplicates(converted_input) == 1)
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


char	**convert_input(int argc, char *argv[])
{
	char	**converted_input;
	int	i;
	int	j;
	int	k;

	converted_input = malloc(sizeof(char *) * (get_max_stack_length(argv, argc) + 1));
	if (converted_input == NULL)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		char	**split;

		split = ft_split(argv[i], ' ');
		if (split == NULL)
			return (NULL);
		k = 0;
		while (split[k])
		{
			converted_input[j] = ft_strdup(split[k]);
			if (converted_input[j] == NULL)
				return (NULL);
			j++;
			k++;
		}
		i++;
		ft_free_split(split);
	}
	converted_input[j] = NULL;
	return (converted_input);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	char	**converted_input;
	int	i;

	if (argc == 1)
	{
		return (0);
	}
	converted_input = convert_input(argc, argv);
	if (converted_input == NULL)
		return (1);
	i = 0;
	// while(converted_input[i])
	// {
	// 	printf("converted_input: %s\n", converted_input[i]);
	// 	i++;
	// }
	check_input(converted_input);
	stack_a = create_stack_a(argv, argc);
	// print_stack(stack_a, 'A');
	stack_a = sort_stack(stack_a);
	// printf("median: %d\n" ,get_median(stack_a));
	// print_stack(stack_a, 'A');
	free(stack_a.stack);
	free(stack_a.chunks.chunks);
	ft_free_split(converted_input);
	return (0);
}
