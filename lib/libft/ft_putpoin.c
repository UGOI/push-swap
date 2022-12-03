/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 01:56:11 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/23 19:53:49 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdint.h>

void	ft_putpoin(void *ptr)
{
	unsigned long long	number;

	number = (unsigned long long)ptr;
	ft_putstr_fd("0x", 1);
	ft_put_unsig_long_nbr_base(number, "0123456789abcdef");
}
