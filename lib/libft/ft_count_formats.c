/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_formats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:35:33 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/23 19:24:38 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#define CONVS "cspdiuxX%"

int	ft_count_formats(const char *restrict format)
{
	int			args;
	char const	*convs;

	convs = CONVS;
	args = 0;
	while (*format)
	{
		if (*format++ == '%')
		{
			if (ft_strchr(convs, *format) && *format)
				args++;
		}
	}
	return (args);
}
