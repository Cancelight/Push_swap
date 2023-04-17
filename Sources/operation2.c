/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:16:29 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/17 12:22:57 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_op(t_blist **stack_c)
{
	t_blist	*temp;

	temp = (*stack_c)->next;
	push_lstadd_front(stack_c, push_lstnew(temp->content, temp->index));
	temp = (*stack_c)->next;
	temp->next = temp->next->next;
}

void	insert_index(t_blist **stack_a)
{
	int		i;
	int		size;
	t_blist	*min;
	t_blist	*temp;

	i = 0;
	size = push_lstsize(*stack_a);
	while (i < size)
	{
		min = *stack_a;
		while (min->index != -1 && min != NULL)
			min = min->next;
		temp = *stack_a;
		while (temp != NULL)
		{
			if (min->content > temp->content && temp->index == -1)
				min = temp;
			temp = temp->next;
		}
		min->index = i++;
	}
}

int	max_bit(int a)
{
	int	b;

	b = 0;
	while (a)
	{
		a = a >> 1;
		b++;
	}
	return (b);
}

void	arrange_stack(t_blist **stack_a, t_blist **stack_b, int bit)
{
	int		k;
	int		i;
	t_blist	*temp;

	k = -1;
	while (++k <= bit)
	{
		i = -1;
		temp = *stack_a;
		while (*stack_a != NULL && temp->index != i)
		{
			if (temp->index >> k & 1)
			{
				if (i == -1)
					i = temp->index;
				rotate_op(stack_a);
				write_op("ra");
			}
			else
				push_op(stack_a, stack_b, "pb");
			temp = *stack_a;
		}
		while (push_lstsize(*stack_b))
			push_op(stack_b, stack_a, "pa");
	}
}

int	control(t_blist *stack_a)
{
	int	i;

	i = stack_a->index;
	while (stack_a != NULL)
	{
		if (stack_a->index != i)
			return (1);
		stack_a = stack_a->next;
		i++;
	}
	return (0);
}
