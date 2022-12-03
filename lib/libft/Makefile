SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
						ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_atoi_base.c \
							ft_count_formats.c ft_numlen_base.c ft_numlen.c ft_print_bigx.c ft_print_c.c ft_print_d.c ft_print_i.c \
								ft_print_in_format.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c ft_ptrlen.c ft_put_unsig_long_nbr_base.c \
									ft_put_unsig_nbr_fd.c ft_putnbr_base.c ft_putpoin.c ft_unumlen.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

BONUS_O	= ${BONUS:.c=.o}

NAME	= libft.a

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			@${RM} ${OBJS} ${BONUS_O}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

bonus:		${BONUS_O} ${OBJS}
			@ar -rcs ${NAME} ${BONUS_O} ${OBJS}

.PHONY:		all clean fclean re bonus
