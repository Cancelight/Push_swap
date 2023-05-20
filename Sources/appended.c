/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appended.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:10:41 by bkiziler          #+#    #+#             */
/*   Updated: 2023/05/20 18:03:21 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	size_apart(int ac, char **av, t_blist **stack_a)
{
	int		i;
	int		k;
	char	**temp;
	int		count;

	i = 1;
	while (i < ac)
	{
		k = 0;
		count = 0;
		push_alnum(av[i]);
		temp = push_split(av[i++], 32, &count);
		while (k < count)
			push_lstadd_back(stack_a, push_lstnew(push_atoi(temp[k++]), -1));
		k = 0;
		if (*stack_a == NULL)
			exit_game(NULL);
		while (k < count)
			free(temp[k++]);
		free(temp);
	}
}

void	two_base(t_blist **stack_c)
{
	if (!control(*stack_c))
		return ;
	rotate_op(stack_c);
	write_op("ra");
}

void	three_base(t_blist **stack_c, int i)
{
	if (i > (*stack_c)->index && i > push_lstlast(*stack_c)->index)
	{
		rerotate_op(stack_c);
		write_op("rra");
		if (control(*stack_c))
		{
			swap_op(stack_c);
			write_op("sa");
		}
	}
	else if ((*stack_c)->index == i + 1 && control(*stack_c))
	{
		swap_op(stack_c);
		write_op("sa");
		if (control(*stack_c))
		{
			rerotate_op(stack_c);
			write_op("rra");
		}
	}
	else if (control(*stack_c))
	{
		rotate_op(stack_c);
		write_op("ra");
	}
}

void	more_base(t_blist **stack_a, t_blist **stack_b)
{
	int	i;

	i = 0;
	if (*stack_b != NULL)
		i++;
	if ((*stack_a)->next->index == i)
	{
		swap_op(stack_a);
		write_op("sa");
	}
	while ((*stack_a)->index != i)
	{
		rerotate_op(stack_a);
		write_op("rra");
	}
	push_op(stack_a, stack_b, "pb");
	if (push_lstsize(*stack_a) == 3)
	{
		three_base(stack_a, (*stack_a)->next->index);
		while (*stack_b != NULL)
			push_op(stack_b, stack_a, "pa");
		return ;
	}
	else
		more_base(stack_a, stack_b);
}

void	exit_game(char *str)
{
	ft_putstr_fd((str), 2);
	exit(0);
}
