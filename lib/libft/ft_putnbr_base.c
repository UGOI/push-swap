/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:21:24 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/23 17:59:10 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

static int	ft_get_str_legth(char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_get_str_legth(base) <= 1)
		return (0);
	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' )
			return (0);
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	if (!ft_check_base(base))
		return ;
	if (nbr >= (unsigned int) ft_get_str_legth(base))
		ft_putnbr_base(nbr / ft_get_str_legth(base), base);
	write(1, &base[nbr % ft_get_str_legth(base)], 1);
}
