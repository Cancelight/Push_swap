/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:03:40 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/08 17:16:14 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_op(p_list *stack_c)
{
	p_list *temp;

	if (ft_lstsize(stack_c <= 0))
		return ;
	temp = stack_c->next;
	stack_c->next = stack_c->next->next;
	ft_lstadd_back(stack_c, temp);
	free(temp);
	op_count;
}

int	rotate_op(p_list *stack_c)
{
	p_list *temp;

	if (ft_lstsize(stack_c) <= 2)
		return (0);
	temp = stack_c->next;
	stack_c->next = stack_c->next->next;
	ft_lstadd_back(stack_c, temp);
	free(temp);

}

void	rr_op(p_list *stack_c, p_list *stack_d)
{
	//girme durumaları için condition oluştur
	if (rotate_op(stack_c) && rotate_op(stack_d))
		op_count;
	else if(rotate_op(stack_c) || rotate_op(stack_d))
		op_count;
	else
		return ;
}

int	rerotate_op(p_list *stack_c)
{
	p_list *temp;
	p_list *stemp;

	if (ft_lstsize(stack_c) <= 2)
		return (0);
	temp = stack_c;
	while (temp->next->next != NULL)
		temp = temp->next;
	stemp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_c, stemp);
	free(stemp);
	free(temp);
	return (1);
}

void	rrr_op(p_list *stack_c, p_list *stack_d)
{
	//girme durumaları için condition oluştur
	if (rerotate_op(stack_c) && rerotate_op(stack_d))
		op_count;
	else if(rerotate_op(stack_c) || rerotate_op(stack_d))
		op_count;
	else
		return ;
}
