/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:12 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/14 20:11:31 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	t_blist *stack_a;
	t_blist *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac)
		parse(ac, av, stack_a, stack_b);
}

void	parse(int ac, char **av, t_blist *stack_a, t_blist *stack_b)
{
	int	bit;

	size_apart(ac, av, &stack_a);
	insert_index(&stack_a);
	bit = max_bit(push_lstsize(stack_a) - 1);
	while (control(stack_a))
		arrange_stack(&stack_a, &stack_b, bit);
}
