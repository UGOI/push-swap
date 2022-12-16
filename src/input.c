/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:26:49 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/16 17:59:03 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
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

int	is_converted_int(char **converted_input)
{
	int	i;

	i = 0;
	while (converted_input[i])
	{
		if (is_str_digit(converted_input[i]) == 0
			|| ft_latoi(converted_input[i]) > INT_MAX
			|| ft_latoi(converted_input[i]) < INT_MIN
			|| ft_strlen(converted_input[i]) > 11)
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
	if (is_converted_int(converted_input) == 0
		|| has_duplicates(converted_input) == 1)
	{
		errprintf("Error\n");
		exit(1);
	}
}

char	**convert_input(int argc, char *argv[])
{
	char	**converted_input;
	int		i;
	int		j;
	int		k;
	char	**split;

	converted_input = malloc(sizeof(char *)
			* (get_max_stack_length(argv, argc) + 1));
	if (converted_input == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			return (NULL);
		k = 0;
		while (split[k])
			converted_input[j++] = ft_strdup(split[k++]);
		ft_free_split(split);
	}
	converted_input[j] = NULL;
	return (converted_input);
}
