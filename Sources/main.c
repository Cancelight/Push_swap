/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:12 by bkiziler          #+#    #+#             */
/*   Updated: 2023/05/03 19:16:59 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	t_blist	*stack_a;
	t_blist	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac > 1)
		parse(ac, av, stack_a, stack_b);
}

void	parse(int ac, char **av, t_blist *stack_a, t_blist *stack_b)
{
	int	bit;

	size_apart(ac, av, &stack_a);
	insert_index(&stack_a);
	if (!control(stack_a))
		exit(0);
	if (push_lstsize(stack_a) == 2)
		two_base(&stack_a);
	else if (push_lstsize(stack_a) == 3)
		three_base(&stack_a, stack_a->next->index);
	else if (push_lstsize(stack_a) == 4 || push_lstsize(stack_a) == 5)
		more_base(&stack_a, &stack_b);
	else
	{
		bit = max_bit(push_lstsize(stack_a) - 1);
		arrange_stack(&stack_a, &stack_b, bit, -1);
	}
}
