#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"


int main(int argc, char *argv[])
{
    char    *stack_arg;
    (void)argc;
    int     *stack;

    stack_arg = argv[1];
    stack = create_stack(stack_arg);
    ft_printf("%d\n", stack[0]);
    free(stack);
    return (0);
}