/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:16:29 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/13 14:22:14 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_op(p_list *stack_c, char *str)
{
	p_list	*temp;

	if (ft_lstsize(stack_c) <= 1)
		return ;
	temp = stack_c->next->next;
	stack_c->next = NULL;
	ft_lstadd_front(&stack_c, temp);
	free(temp);
	ft_printf("%s\n", str);
}

void	insert_index(p_list *stack_a)
{
	int		i;
	int		size;
	p_list	*min;
	p_list	*temp;

	i = 0;
	size = ft_lstsize(stack_a);
	temp = stack_a;
	min = stack_a;
	while (i < size)
	{
		while (temp != NULL)
		{
			if (min->content > temp->content && temp->index == -1)
				min = temp;
			temp = temp->next;
		}
		min->index = i++;
		min = stack_a;
		while (min->index != -1 && min != NULL)
			min = min->next;
	}
}

int	max_bit(int a)
{
	int	c;
	int	b;

	b = 0;
	c = 0;
	c = c | a;
	while (c >> b)
		b++;
	return (++b);
}

void	arrange_stack(p_list *stack_a, p_list *stack_b, int bit)
{
	int		k;
	p_list	*temp;

	k = -1;
	temp = stack_a;
	while (++k <= bit)
	{
		while (temp != NULL)
		{
			if (temp->index >> k && 1)
				rotate_op(stack_a, "ra");
			else
				push_op(stack_a, stack_b, "pb");
		}
		while (stack_b != NULL)
			push_op(stack_b, stack_a, "pa");
	}
}

int	control(p_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		if (stack_a->index != i)
			return (1);
		i++;
		stack_a = stack_a->next;
	}
	return (0);
}
