/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:44:32 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/23 19:53:35 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_print_s(char	*arg)
{
	if (!arg)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg));
}
