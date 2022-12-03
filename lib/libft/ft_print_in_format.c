/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_in_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:55:44 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/23 19:53:29 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_print_in_format(char conv, va_list ap)
{
	if (conv == 's')
		return (ft_print_s(va_arg(ap, char *)));
	if (conv == 'd')
		return (ft_print_d(va_arg(ap, signed int)));
	if (conv == 'c')
		return (ft_print_c((char)va_arg(ap, int)));
	if (conv == 'p')
		return (ft_print_p(va_arg(ap, void *)));
	if (conv == 'x')
		return (ft_print_x(va_arg(ap, unsigned long int)));
	if (conv == 'X')
		return (ft_print_bigx(va_arg(ap, unsigned long int)));
	if (conv == 'i')
		return (ft_print_i(va_arg(ap, int)));
	if (conv == 'u')
		return (ft_print_u(va_arg(ap, unsigned int)));
	if (conv == '%')
		return (ft_print_c('%'));
	return (0);
}
