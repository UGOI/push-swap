/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:09:56 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/06 20:02:41 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/libft.h"
#include "./include/ft_printf.h"
#include "./include/pushswap.h"

t_stack	sort_stack_a(t_stack stack_a)
{
	t_stack	stack_b;

	stack_b = create_stack_b(stack_a.max_length);
	// stack_a = swap(stack_a);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// push(&stack_b, &stack_a);
	stack_a = rrotate(stack_a);
	free(stack_b.stack);

	return (stack_a);
}
