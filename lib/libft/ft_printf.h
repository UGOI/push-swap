/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:34:13 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/23 19:25:58 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>

int		ft_count_formats(const char *format);
int		ft_printf(const char *format, ...);
int		ft_print_in_format(char conv, va_list	ap);
int		ft_numlen(int n);
void	ft_putpoin(void *ptr);
int		ft_ptrlen(void *ptr);
void	ft_putnbr_base(int nbr, char *base);
void	ft_put_unsig_nbr_fd(int unsigned n, int fd);
void	ft_put_unsig_long_nbr_base(unsigned long long nbr, char *base);
int		ft_numlen_base(unsigned long long n, int base);

int		ft_print_s(char	*str);
int		ft_print_d(signed int arg);
int		ft_print_c(char arg);
int		ft_print_p(void *arg);
int		ft_print_x(unsigned int arg);
int		ft_print_bigx(unsigned int arg);
int		ft_print_i(int arg);
int		ft_print_u(unsigned int arg);
int		ft_unumlen(unsigned int n);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
#endif
