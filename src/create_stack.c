#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"

static int str_arr_len(char **str_arr)
{
    int i;

    i = 0;
    while (str_arr[i])
    {
        i++;
    }
    return(i);
}

static void populate_stack(int *stack, char **src)
{
    int i;

    i = 0;
    while (src[i])
    {
        stack[i] = ft_atoi(src[i]);
        i++;
    }
}

int *create_stack(char *stack_arg)
{
    char    **stack_arg_split;
    int stack_arg_len;
    int *stack;

    stack_arg_split = ft_split(stack_arg, ' ');
    stack_arg_len = str_arr_len(stack_arg_split);
    stack = ft_calloc(stack_arg_len, sizeof(int));
    populate_stack(stack, stack_arg_split);
    free(stack_arg_split);
    return (stack);
}
