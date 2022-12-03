/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsig_long_nbr_base.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:21:24 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/23 16:34:47 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

static unsigned long long	ft_get_str_length(char *str)
{
	unsigned long long	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_get_str_length(base) <= 1)
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

void	ft_put_unsig_long_nbr_base(unsigned long long nbr, char *base)
{
	if (!ft_check_base(base))
		return ;
	if (nbr >= ft_get_str_length(base))
		ft_put_unsig_long_nbr_base(nbr / ft_get_str_length(base), base);
	write(1, &base[nbr % ft_get_str_length(base)], 1);
}
