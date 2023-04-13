/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:12 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/13 13:53:32 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	p_list *stack_a;
	p_list *stack_b;

	if (ac)
		parse(ac, av, stack_a, stack_b);
}

void	parse(int ac, char **av, p_list *stack_a, p_list *stack_b)
{
	int	bit;

	size_apart(ac, av, stack_a);
	insert_index(stack_a);
	bit = max_bit(ft_lstsize(stack_a) - 1);
	while (control(stack_a))
		arrange_stack(stack_a, stack_b, bit);
}
