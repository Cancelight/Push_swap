/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:16:29 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/08 17:42:50 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	swap_op(p_list *stack_c)
{
	p_list *temp;

	if (ft_lstsize(stack_c) <= 1)
		return (0);
	temp = stack_c->next->next;
	stack_c->next = NULL;
	ft_lstadd_front(&stack_c, temp);
	free(temp);
	return (1);
}

void	ss_op(p_list *stack_c, p_list *stack_d)
{
	//eğer hem sa hem de sb için uygunsa durumunu kontrol et
	if (sa_op(stack_c) && sb_op(stack_d))
		op_count;
	else if(sa_op(stack_c) || sb_op(stack_d))
		op_count;
	else
		return ;
}

void	insert_index(p_list *stack_a)
{
	int	i;
	int	size;
	p_list *min;
	p_list *temp;

	i = 0;
	size = ft_lstsize(stack_a);
	temp = stack_a->next;
	min = stack_a->next;
	while (i < size)
	{
		while(temp != NULL)
		{
			if(min->content > temp->content && temp->index == -1)
				min = temp;
			temp = temp->next;
		}
		min->index = i++;
	}
}
